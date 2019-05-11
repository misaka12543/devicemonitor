#ifndef SHOW_LOG_PAGE_H
#define SHOW_LOG_PAGE_H

#include <QMainWindow>

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
};

#endif // SHOW_LOG_PAGE_H
