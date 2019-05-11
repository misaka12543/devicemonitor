#ifndef TEV_MONITOR_PAGE_H
#define TEV_MONITOR_PAGE_H

#include <QMainWindow>

namespace Ui {
class tev_monitor_page;
}

class tev_monitor_page : public QMainWindow
{
    Q_OBJECT

public:
    explicit tev_monitor_page(QWidget *parent = nullptr);
    ~tev_monitor_page();

private:
    Ui::tev_monitor_page *ui;
};

#endif // TEV_MONITOR_PAGE_H
