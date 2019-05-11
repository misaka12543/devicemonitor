#include "temp_monitor_page.h"
#include "ui_temp_monitor_page.h"

temp_monitor_page::temp_monitor_page(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::temp_monitor_page)
{
    ui->setupUi(this);
}

temp_monitor_page::~temp_monitor_page()
{
    delete ui;
}

void temp_monitor_page::receive_show()
{
    this->show();
}

void temp_monitor_page::on_pushButton_clicked()
{
    this->hide();
    emit back_main();
}
