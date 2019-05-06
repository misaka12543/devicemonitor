#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "setting_define_other.h"
#include "setting_page.h"
#include "cancel_bugs.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void receive_show();                //receive show signal

    void on_groupBox_toggled(bool arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void textses();

private:
    Ui::MainWindow *ui;

signals:
    void setting_show();        //setting page
    void listview_show();       //list ver main page
    void tempsdetail_show();    //temp detail page
    void humidetail_show();     //humi detail page
    void ultdetil_show();       //ULS  detail page
    void tevdetail_show();      //TEV  detail page
    void vibdetail_show();      //VIB  detail page
    void sf6detail_show();      //SF6  detail page
    void log_show();            //log  detail page

    void text_change();

};

#endif // MAINWINDOW_H
