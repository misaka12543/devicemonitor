#ifndef SETTING_PAGE_H
#define SETTING_PAGE_H

#include <QMainWindow>
//#include "setting_define_other.h"
#include "cancel_bugs.h"

namespace Ui {
class setting_page;
}

class setting_page : public QMainWindow
{
    Q_OBJECT

public:
    explicit setting_page(QWidget *parent = nullptr);
    ~setting_page();

private slots:
    void on_checkBox_stateChanged(int arg1);
    void receive_show();
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::setting_page *ui;
signals:
    void back_main();
};

#endif // SETTING_PAGE_H
