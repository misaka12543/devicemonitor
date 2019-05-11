#include "vib_monitor_page.h"
#include "ui_vib_monitor_page.h"

vib_monitor_page::vib_monitor_page(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::vib_monitor_page)
{
    ui->setupUi(this);
}

vib_monitor_page::~vib_monitor_page()
{
    delete ui;
}
