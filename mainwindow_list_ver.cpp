#include "mainwindow_list_ver.h"
#include "ui_mainwindow_list_ver.h"
//#include "setting_define_other.h"
MainWindow_list_ver::MainWindow_list_ver(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow_list_ver)
{
    ui->setupUi(this);

}

MainWindow_list_ver::~MainWindow_list_ver()
{
    delete ui;
}

void MainWindow_list_ver::on_pushButton_clicked()
{
    this->hide();
    this->setWindowFlag(Qt::SubWindow);
    emit back_main();
}
void MainWindow_list_ver::receive_show()
{
    this->show();
    this->setWindowFlag(Qt::Window);
    this->showFullScreen();
}
