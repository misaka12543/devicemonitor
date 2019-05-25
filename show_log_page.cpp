#include "show_log_page.h"
#include "ui_show_log_page.h"
#include <QFileDialog>
#include <qfile.h>

#include <QTextStream>

extern QDir Log_main;
extern QDir log_detail;

QDir Log_main("/root/DeviceMonitorLog");
QDir log_detail("/root/DeviceMonitorLog/Log");
QFile humi_log("/root/DeviceMonitorLog/Log/humi_log");
QFile sf6_log("/root/DeviceMonitorLog/Log/sf6_log");
QFile temp_log("/root/DeviceMonitorLog/Log/temp_log");
QFile vib_log("/root/DeviceMonitorLog/Log/vib_log");
QFile tev_log("/root/DeviceMonitorLog/Log/tev_log");
QFile ult_log("/root/DeviceMonitorLog/Log/ult_log");
QFile log_log("/root/DeviceMonitorLog/Log/log_log");
QFile log_main("/root/DeviceMonitorLog/Log.txt");

show_log_page::show_log_page(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::show_log_page)
{
    ui->setupUi(this);
}

show_log_page::~show_log_page()
{
    delete ui;
}

void show_log_page::receive_show()
{
    this->show();
}

void show_log_page::on_pushButton_clicked()
{
    this->hide();
    emit back_main();
}

int show_log_page::read_log(int x)
{

    //not finished!!!!!!!!
    switch(x)
    {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    default:
        break;
    }
    if(!log_main.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return -1;
    }

    QTextStream txtInput(&log_main);
    QString lineStr;
    while(!txtInput.atEnd())
    {
        lineStr = txtInput.readLine();
    }

    log_main.close();
    return 0;
}

int show_log_page::write_log(int x)
{

    if(!log_main.open(QIODevice::WriteOnly | QIODevice::Text))
    {

        return -1;
    }

    QTextStream txtOutput(&log_main);
    QString s1("123");
    quint32 n1(123);

    txtOutput << s1 << endl;
    txtOutput << n1 << endl;

    log_main.close();
    return 0;
}


