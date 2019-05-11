#include "tev_monitor_page.h"
#include "ui_tev_monitor_page.h"

tev_monitor_page::tev_monitor_page(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tev_monitor_page)
{
    ui->setupUi(this);
}

tev_monitor_page::~tev_monitor_page()
{
    delete ui;
}
