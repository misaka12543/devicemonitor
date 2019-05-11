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
