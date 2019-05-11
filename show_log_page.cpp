#include "show_log_page.h"
#include "ui_show_log_page.h"

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
