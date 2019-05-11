#include "show_log_page.h"
#include "ui_show_log_page.h"
#include <QFileDialog>
#include <qfile.h>

#include <QTextStream>

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
    QFile humi_log("~/DeviceMonitor/Log/humi_log");
    QFile sf6_log("~/DeviceMonitor/Log/sf6_log");
    QFile temp_log("~/DeviceMonitor/Log/temp_log");
    QFile vib_log("~/DeviceMonitor/Log/vib_log");
    QFile tev_log("~/DeviceMonitor/Log/tev_log");
    QFile ult_log("~/DeviceMonitor/Log/ult_log");
    QFile log_log("~/DeviceMonitor/Log/log_log");
    QFile f;
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
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return -1;
    }

    QTextStream txtInput(&f);
    QString lineStr;
    while(!txtInput.atEnd())
    {
        lineStr = txtInput.readLine();
    }

    f.close();
    return 0;
}

int show_log_page::write_log(int x)
{
    QFile humi_log("~/DeviceMonitor/Log/humi_log");
    QFile sf6_log("~/DeviceMonitor/Log/sf6_log");
    QFile temp_log("~/DeviceMonitor/Log/temp_log");
    QFile vib_log("~/DeviceMonitor/Log/vib_log");
    QFile tev_log("~/DeviceMonitor/Log/tev_log");
    QFile ult_log("~/DeviceMonitor/Log/ult_log");
    QFile f("~/DeviceMonitor/Log/log_log");
    if(!f.open(QIODevice::WriteOnly | QIODevice::Text))
    {

        return -1;
    }

    QTextStream txtOutput(&f);
    QString s1("123");
    quint32 n1(123);

    txtOutput << s1 << endl;
    txtOutput << n1 << endl;

    f.close();
    return 0;
}


