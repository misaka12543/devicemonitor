#include "mainwindow.h"
#include <QApplication>
#include <QtSerialPort>

#include "mainwindow_list_ver.h"
#include "setting_page.h"
#include "ult_monitor_page.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MainWindow_list_ver wlv;
    setting_page setp;
    ULT_monitor_Page ult;

    w.show();

    QObject::connect(&w,SIGNAL(setting_show()),&setp,SLOT(receive_show()));
    QObject::connect(&w,SIGNAL(listview_show()),&wlv,SLOT(receive_show()));
    QObject::connect(&w,SIGNAL(ultdetil_show()),&ult,SLOT(receive_show()));
    QObject::connect(&setp,SIGNAL(back_main()),&w,SLOT(receive_show()));
    QObject::connect(&wlv,SIGNAL(back_main()),&w,SLOT(receive_show()));
    QObject::connect(&ult,SIGNAL(back_main()),&w,SLOT(receive_show()));

    return a.exec();
}
#ifndef QT_NO_DEBUG_OUTPUT

void bugtest()
{
    if(ture)
    {
        BOOL asdasdas,aasadasaa;
        asdasdas=flase;
        aasadasaa = TRUE;

    }
}
#endif
