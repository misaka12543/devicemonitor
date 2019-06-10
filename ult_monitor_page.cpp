#include "ult_monitor_page.h"
#include "ui_ult_monitor_page.h"
#include "scarray.h"


ULT_monitor_Page::ULT_monitor_Page(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ULT_monitor_Page)
{
    ui->setupUi(this);

    ult_port = new QSerialPort();
    //initUI();

    //QObject::connect(this,&SIGNAL(refresh_button_clicked()),&SLOT(openPort()));
}

ULT_monitor_Page::~ULT_monitor_Page()
{
    if(ult_port->isOpen())//close port if window close
    {
        ult_port->close();
    }
    delete ult_port;//release memory
    delete ui;
}
void initUI()
{
    while (false) {
        //do nothing
    }
//    refresh_button = new QPushButton();

//    select_spin = new QSpinBox();


}
void ULT_monitor_Page::on_pushButton_clicked()
{
    this->hide();
    emit back_main();
}
void ULT_monitor_Page::receive_show()
{
    this->show();
}

QString port_nameList()
{
    QString portname;
    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        portname=info.portName();
    }
    return portname;
}
void ULT_monitor_Page::openPort()
{
   // QSerialPort *ult_port = new QSerialPort();
    QString portname = port_nameList();

    //if port opening,close it
    if(ult_port->isOpen())
    {
        ult_port->clear();
        ult_port->close();
    }
    ult_port->setPortName(portname);

    if(!ult_port->open(QIODevice::ReadWrite))                                 //try RW mode open port
    {
        qDebug()<<portname<<"open failed";
    }

    ult_port->setBaudRate(QSerialPort::Baud115200,QSerialPort::AllDirections);//baudrate: 115200; deriction: all
    ult_port->setDataBits(QSerialPort::Data8);                                //data bit: 8
    ult_port->setFlowControl(QSerialPort::NoFlowControl);
    ult_port->setParity(QSerialPort::NoParity);
    ult_port->setStopBits(QSerialPort::OneStop);

    QObject::connect(ult_port,SIGNAL(readyRead()),this,SLOT(receive_port_data()));

}

///recive all data from port
QByteArray ULT_monitor_Page::receive_port_data()
{
    QByteArray data = ult_port->readAll();      //all_really_read_data_here



    bool fail_data=false;                   //broken data flag
    const int alldatalen = data.length();   //data length
    int data_leng=0x00;                     //length data 0x00~0xff
    int datahex;                            //current data
    int data_offset=0;                      //if first data not 0xaa,0xaa position is 0+this
    bool need_head_check = false;
    bool head_check = false;                //head check flag
    //data.count();   //???wtf
    for (int tester=0;tester<=alldatalen;tester++)
    {
        datahex = data[tester];
        if(!head_check)                     //check 1st 0xaa position,and set value to data_offset (always 0)
        {
             if(datahex == 0xaa && tester==0)
             {
                 data_offset = 0;
                 break;
             }
             if(datahex != 0xaa && tester==0)
             {
                need_head_check=true;
                continue;
             }
             if(tester==alldatalen&&need_head_check)
             {
                 fail_data = true;
                 break;                          //if can't find data head
             }
             if(need_head_check)
             {
                 if(datahex==0xaa)
                 {
                     need_head_check=false;
                     data_offset=tester;
                 }
                 else
                 {
                     continue;
                 }
             }//need_head_check
             head_check=true;
        }// head_check over
        else {

        }
    }//tester for block end
    if(fail_data)
    {
        data = nullptr;//piu~
        return data;
    }
    data_split(data,data_offset);
    data_leng=data[data_offset+data_leng_offset_receive];//find data
    data_read(data,data_offset,data_leng);

    return data;
}

///read useful data and return
void ULT_monitor_Page::data_read(QByteArray data,int dataOffset, int leng)              //Rewrite!
{
    int count = 0;
    QByteArray true_data = QByteArray::fromHex("");
    int current_data=0x00;

    if(leng==0x00)
        true_data = QByteArray::fromHex("");    //empty data phase
    else
    {
        for (;count<leng;count++)
        {
            current_data=data.at(dataOffset+count);//[dataOffset+count];
            true_data.append(current_data);
        }
    }
    //here,true data is all data really need
    ;
}
QByteArray ULT_monitor_Page::data_split(QByteArray data,int dataOffset)  //rewrite!
{
    QByteArray taildata;
    QByteArray tmp_data;
    QByteArray out_data;            //data_output
    QByteArray current_data;
    taildata.fromHex("cc33c33c");   //taildata
    int blocks = 0;                 //how many blocks read
    int leng_check;                 //data length read from data
    int leng=data.length();         //whole data length
    int sensor = 0x00;
    int type = 0x00;

    if(dataOffset)                  //remove head
    {
        data.remove(0,dataOffset+1); //remove junk data and head(0xaa)
    }
    else
    {
        data.remove(0,1);           //remove head 0xaa
    }

    sensor=data.at(1);              //get sensor
    type = data.at(2);              //get type
    leng_check = data.at(3);        //get data_length


    blocks = data.count(taildata);  //blocks count

    if(blocks>1)                    //it said data not include time,200ms per point,need check length everyblock
    {
        for (;;)
        {

        }
    }
    else
    {
        data.remove(0,3);           //remove whole head

        for (int loop_b1=0;loop_b1<=leng_check;loop_b1+=4)   //loop for read per data block
        {
            for (int loop_b2=0;loop_b2<4;loop_b2++)         //loop for read per small block
            {
                current_data.prepend(data.at(loop_b1+loop_b2)); //read data and rev
            }
            tmp_data.append(current_data);                      //now,tmp_data have current_data's data

        }

    }
    return out_data;                //warning! Data out here without any define
}




void ULT_monitor_Page::on_pushButton_2_clicked()    //refresh button
{
    emit refresh_button_clicked();


    openPort();
    receive_port_data();

    this->ui->Current_RSSI->setText("");
}
