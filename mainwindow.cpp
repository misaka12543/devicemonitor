#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "setting_value.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(this,SIGNAL(text_change()),this,SLOT(textses()));
    this->setWindowFlag(Qt::Window);
    this->showFullScreen();

}

MainWindow::~MainWindow()
{
    delete ui;
}



//delete this part when release
void MainWindow::on_groupBox_toggled(bool arg1)
{
    bool sss=arg1;
    if(sss)
    {
        sss=arg1;
    }
}

//show current page
void MainWindow::receive_show()
{
    this->show();
    //full screen
    this->setWindowFlag(Qt::Window);
    this->showFullScreen();
}

////test block
void MainWindow::textses()
{


    if(Setting_value::Temp_Statue_get())
    {
        //change text
        QLabel *pLabel = new QLabel(this);
        pLabel->setText("Hello World");
    }
}


//test button
void MainWindow::on_pushButton_3_clicked()
{
    emit text_change();
}

/**
*   just switch window
*/

//switch to list_main_view page
void MainWindow::on_pushButton_5_clicked()
{
    this->hide();
    this->setWindowFlag(Qt::SubWindow);
    emit listview_show();
}
//switch to setting page
void MainWindow::on_pushButton_2_clicked()
{
    this->hide();
    emit setting_show();
}

/**
* switch page like popup window
*/

//switch to humi page
void MainWindow::on_pushButton_clicked()
{
    //this->hide();
    emit humidetail_show();
}

//switch to UTL page
void MainWindow::on_pushButton_4_clicked()
{
   // this->hide();
    emit ultdetil_show();
}

//switch to vib page
void MainWindow::on_VIB_button_clicked()
{
    //this->hide();
    emit vibdetail_show();
}

//switch to tev page
void MainWindow::on_TEV_button_clicked()
{
    //this->hide();
    emit tevdetail_show();
}

//switch to temp page
void MainWindow::on_Temp_Button_clicked()
{
    //this->hide();
    emit tempsdetail_show();
}

//switch to sf6 page
void MainWindow::on_SF6_button_clicked()
{
    //this->hide();
    emit sf6detail_show();
}
//switch to log page
void MainWindow::on_pushButton_7_clicked()
{
    emit log_show();
}
//exit button
void MainWindow::on_pushButton_6_clicked()
{
    QApplication::exit(0);
}
