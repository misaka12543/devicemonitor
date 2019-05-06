#ifndef ULT_MONITOR_PAGE_H
#define ULT_MONITOR_PAGE_H

#include <QMainWindow>
#include <QtSerialPort>
#include <QSpinBox>
#include "cancel_bugs.h"

namespace Ui {
class ULT_monitor_Page;
}

class ULT_monitor_Page : public QMainWindow
{
    Q_OBJECT

public:
    explicit ULT_monitor_Page(QWidget *parent = nullptr);
    ~ULT_monitor_Page();

    QStringList port_NameList();
    void initUI();

    ///split data
    QByteArray data_split(QByteArray data,int dataOffset);

    ///analize data,save all data into one SCarray(it's a int array)
    void data_read(QByteArray data,int dataOffset, int leng);

    //send structure
    //head addr 03 command length  4bittail
//eg:
    //aa    01  03   a0      00   cc 33 c3 3c

    //receive structure
    /* head addr 03 length                data                 4bittail
  *eg
     * aa   01   03   08        fe 08 00 00   af 78 01 00     cc 33 c3 3c
     *                           |strength|      |time|
     *
     * hex                       0x000008fe    0x000178af
     * dec                          2302         96431
    */
    ///frame head
    int Headsign                    = 0xaa;
    int head_offset                 = 0;

    ///command
    int command_ReadAddr            = 0xa0;
    int command_ReadData_2k         = 0xa2;
    int command_ReadData_1k         = 0xa3;
    int command_ReadPoint           = 0xa4;
    int command_offset              = 3;

    ///data
    int data_leng_offset_send       = 4;
    int data_leng_offset_receive    = 3;

    ///frame tail
    int frame_tail_1                = 0xcc;
    int frame_tail_2                = 0x33;
    int frame_tail_3                = 0xc3;
    int frame_tail_fin              = 0x3c;
    int frame_tail[4]               = {frame_tail_1,frame_tail_2,frame_tail_3,frame_tail_fin};



private slots:
    ///home button
    void on_pushButton_clicked();

    ///page switch
    void receive_show();

    ///getdatafromport
    void receive_port_data();

    ///refresh button
    void on_pushButton_2_clicked();

    ///openport
    void openPort();



private:
    Ui::ULT_monitor_Page *ui;
    QSerialPort* ult_port;
    QStringList ult_portNameList;

    QSpinBox* port_select;




signals:
    void back_main();
    void refresh_button_clicked();
};

#endif // ULT_MONITOR_PAGE_H
