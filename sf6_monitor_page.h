#ifndef SF6_MONITOR_PAGE_H
#define SF6_MONITOR_PAGE_H

#include <QMainWindow>

namespace Ui {
class sf6_monitor_page;
}

class sf6_monitor_page : public QMainWindow
{
    Q_OBJECT

public:
    explicit sf6_monitor_page(QWidget *parent = nullptr);
    ~sf6_monitor_page();

private:
    Ui::sf6_monitor_page *ui;
};

#endif // SF6_MONITOR_PAGE_H
