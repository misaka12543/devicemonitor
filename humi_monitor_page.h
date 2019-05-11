#ifndef HUMI_MONITOR_PAGE_H
#define HUMI_MONITOR_PAGE_H

#include <QMainWindow>

namespace Ui {
class humi_monitor_page;
}

class humi_monitor_page : public QMainWindow
{
    Q_OBJECT

public:
    explicit humi_monitor_page(QWidget *parent = nullptr);
    ~humi_monitor_page();

private:
    Ui::humi_monitor_page *ui;

private slots:
    void receive_show();

    void on_pushButton_clicked();

signals:
    void back_main();
};

#endif // HUMI_MONITOR_PAGE_H
