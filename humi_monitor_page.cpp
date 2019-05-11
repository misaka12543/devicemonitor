#include "humi_monitor_page.h"
#include "ui_humi_monitor_page.h"

humi_monitor_page::humi_monitor_page(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::humi_monitor_page)
{
    ui->setupUi(this);
}

humi_monitor_page::~humi_monitor_page()
{
    delete ui;
}

void humi_monitor_page::receive_show()
{
    this->show();
}


void humi_monitor_page::on_pushButton_clicked()
{
    this->hide();
    emit back_main();
}
