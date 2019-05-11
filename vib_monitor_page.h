#ifndef VIB_MONITOR_PAGE_H
#define VIB_MONITOR_PAGE_H

#include <QMainWindow>

namespace Ui {
class vib_monitor_page;
}

class vib_monitor_page : public QMainWindow
{
    Q_OBJECT

public:
    explicit vib_monitor_page(QWidget *parent = nullptr);
    ~vib_monitor_page();

private:
    Ui::vib_monitor_page *ui;
};

#endif // VIB_MONITOR_PAGE_H
