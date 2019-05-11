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
};

#endif // HUMI_MONITOR_PAGE_H
