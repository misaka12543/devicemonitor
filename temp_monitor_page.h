#ifndef TEMP_MONITOR_PAGE_H
#define TEMP_MONITOR_PAGE_H

#include <QMainWindow>

namespace Ui {
class temp_monitor_page;
}

class temp_monitor_page : public QMainWindow
{
    Q_OBJECT

public:
    explicit temp_monitor_page(QWidget *parent = nullptr);
    ~temp_monitor_page();

private:
    Ui::temp_monitor_page *ui;

private slots:
    void receive_show();

    void on_pushButton_clicked();

signals:
    void back_main();
};

#endif // TEMP_MONITOR_PAGE_H
