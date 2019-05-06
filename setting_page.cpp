#include "setting_page.h"
#include "ui_setting_page.h"
#include "scarray.h"
#include "setting_value.h"

setting_page::setting_page(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::setting_page)
{
    ui->setupUi(this);
}

setting_page::~setting_page()
{
    delete ui;
}

void setting_page::on_checkBox_stateChanged(int arg1)
{
    Setting_value::R_RATE_TEMP_SET(arg1);
}

void setting_page::on_pushButton_clicked()
{
    Setting_value::Temp_Statue_Set(false);
}

void setting_page::on_pushButton_3_clicked()
{
    this->hide();
    emit back_main();
}
void setting_page::receive_show()
{
    this->show();
}
