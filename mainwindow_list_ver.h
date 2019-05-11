#ifndef MAINWINDOW_LIST_VER_H
#define MAINWINDOW_LIST_VER_H

#include <QMainWindow>
//#include "setting_define_other.h"
#include "cancel_bugs.h"

namespace Ui {
class MainWindow_list_ver;
}

class MainWindow_list_ver : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow_list_ver(QWidget *parent = nullptr);
    ~MainWindow_list_ver();

private slots:
    void receive_show();

    void on_pushButton_clicked();

private:
    Ui::MainWindow_list_ver *ui;

signals:
    void back_main();
};

#endif // MAINWINDOW_LIST_VER_H
