#include "sf6_monitor_page.h"
#include "ui_sf6_monitor_page.h"

sf6_monitor_page::sf6_monitor_page(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::sf6_monitor_page)
{
    ui->setupUi(this);
}

sf6_monitor_page::~sf6_monitor_page()
{
    delete ui;
}
