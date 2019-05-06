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

void ULT_monitor_Page::receive_port_data()
{
    QByteArray data = ult_port->readAll();


    bool fail_data=false;
    const int alldatalen = data.length();
    int data_leng=0x00;                     //length data 0x00~0xff
    int datahex;                            //this data
    int data_offset=0;                      //if first data not 0xaa,0xaa position is 0+this
    bool need_head_check = false;
    bool head_check = false;                //head check flag
    data.count();
    for (int tester=0;tester<alldatalen;tester++)
    {
        datahex = data[tester];
        if(!head_check)                     //check 1st 0xaa position,and set value to data_offset
        {
             if(datahex == 0xaa && tester==0)
             {
                 data_offset = 0;
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

             data_split(data,data_offset);
           data_leng=data[data_offset+data_leng_offset_receive];//find data
           head_check=true;
        }// !head_check

        data_read(data,data_offset,data_leng);
    }//tester for block
}
void ULT_monitor_Page::data_read(QByteArray data,int dataOffset, int leng)
{
    int count = 0;
    SCArray true_data;
    int current_data=0x00;

    if(leng==0x00)
        return;
    for (;count<leng;count++)
    {
        current_data=data[dataOffset+count];
        true_data.push_back(current_data);
    }

}
QByteArray ULT_monitor_Page::data_split(QByteArray data,int dataOffset)
{
    int leng=data.length();
    int spliter=0;
    int blocks=0;
    int match_num=1;
    int data_block_leng=0;
    bool next_block=false;

    spliter = dataOffset;

    SCArray the_data;

    for (;spliter<leng;spliter++) {
        int current_dataHex = data[spliter];
//        if(current_dataHex==Headsign)
//            continue;
        if(next_block)
        {
            data_block_leng=data[spliter];
        }
        if(current_dataHex==frame_tail_1)       //frame tail check
        {
            if(spliter<=(leng-4))
            {
                int tail_tester[4] = {data[spliter],data[spliter+1],data[spliter+2],data[spliter+3]};
                int i = 0;
                while (i<4)             //compare tail
                {
                    if(tail_tester[i]==frame_tail[i])
                        match_num += i;
                }
                if(match_num==4)        //frame_tail found
                {
                    blocks++;
                }
               if(leng>=(spliter+5))
               {
                   int head_try = data[spliter];
                   if(head_try==Headsign)
                   {
                       spliter += 6; //jump to next data block
                       next_block=true;
                       continue;
                   }
               }
            }
        }

    }
}
void ULT_monitor_Page::on_pushButton_2_clicked()
{
    emit refresh_button_clicked();
    openPort();
}
