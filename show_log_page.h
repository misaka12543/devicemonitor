#ifndef SHOW_LOG_PAGE_H
#define SHOW_LOG_PAGE_H

#include <QMainWindow>
#include <QFile>

extern QFile humi_log;
extern QFile sf6_log;
extern QFile temp_log;
extern QFile vib_log;
extern QFile tev_log;
extern QFile ult_log;
extern QFile log_log;
extern QFile log_main;

namespace Ui {
class show_log_page;
}

class show_log_page : public QMainWindow
{
    Q_OBJECT

public:
    explicit show_log_page(QWidget *parent = nullptr);
    ~show_log_page();

private:
    Ui::show_log_page *ui;

    ///x mean what file path select
    int read_log(int x);

    ///x mean what file path select
    int write_log(int x);

private slots:
    void receive_show();

    void on_pushButton_clicked();

signals:
    void back_main();
};

#endif // SHOW_LOG_PAGE_H
