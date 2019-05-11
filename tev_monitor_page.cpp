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

void tev_monitor_page::receive_show()
{
    this->show();
}

void tev_monitor_page::on_pushButton_clicked()
{
    this->hide();
    emit back_main();
}
