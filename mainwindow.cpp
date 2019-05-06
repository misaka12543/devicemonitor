#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "setting_value.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(this,SIGNAL(text_change()),this,SLOT(textses()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //open new list
    QLabel *pLabel = new QLabel(this);
    pLabel->setText("Hello World");

}

void MainWindow::on_groupBox_toggled(bool arg1)
{
    bool sss=arg1;
    if(sss)
    {
        sss=arg1;
    }
}

void MainWindow::receive_show()
{
    this->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    emit text_change();
}

////show setting page
void MainWindow::on_pushButton_2_clicked()
{
    this->hide();
    emit setting_show();
}

////show UTL page
void MainWindow::on_pushButton_4_clicked()
{
   // this->hide();
    emit ultdetil_show();
}

////show list_main_view page
void MainWindow::on_pushButton_5_clicked()
{
    this->hide();
    emit listview_show();
}
////
void MainWindow::textses()
{


    if(Setting_value::Temp_Statue_get())
    {
        //change text
        QLabel *pLabel = new QLabel(this);
        pLabel->setText("Hello World");
    }
}
