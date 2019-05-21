#include "mainwindow.h"
#include <QApplication>
#include <QtSerialPort>

//key page
#include "mainwindow_list_ver.h"
#include "setting_page.h"

//log page
#include "show_log_page.h"

//sensors
#include "ult_monitor_page.h"
#include "sf6_monitor_page.h"
#include "vib_monitor_page.h"
#include "temp_monitor_page.h"
#include "tev_monitor_page.h"
#include "humi_monitor_page.h"

extern int app_version ;
extern double app_version_D ;

int app_version = 3;
double app_version_D = app_version*0.1;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    MainWindow_list_ver wlv;

    setting_page setp;

    humi_monitor_page humip;
    temp_monitor_page tempp;
    tev_monitor_page tevp;
    ULT_monitor_Page ultp;
    vib_monitor_page vibp;
    sf6_monitor_page sf6p;


    w.show();

    //signal connect
    QObject::connect(&w,SIGNAL(listview_show()),&wlv,SLOT(receive_show()));

    QObject::connect(&w,SIGNAL(setting_show()),&setp,SLOT(receive_show()));

    QObject::connect(&w,SIGNAL(humidetail_show()),&humip,SLOT(receive_show()));
    QObject::connect(&w,SIGNAL(tempsdetail_show()),&tempp,SLOT(receive_show()));
    QObject::connect(&w,SIGNAL(tevdetail_show()),&tevp,SLOT(receive_show()));
    QObject::connect(&w,SIGNAL(ultdetil_show()),&ultp,SLOT(receive_show()));
    QObject::connect(&w,SIGNAL(vibdetail_show()),&vibp,SLOT(receive_show()));
    QObject::connect(&w,SIGNAL(sf6detail_show()),&sf6p,SLOT(receive_show()));


    QObject::connect(&wlv,SIGNAL(back_main()),&w,SLOT(receive_show()));

    QObject::connect(&setp,SIGNAL(back_main()),&w,SLOT(receive_show()));

    QObject::connect(&humip,SIGNAL(back_main()),&w,SLOT(receive_show()));
    QObject::connect(&tempp,SIGNAL(back_main()),&w,SLOT(receive_show()));
    QObject::connect(&tevp,SIGNAL(back_main()),&w,SLOT(receive_show()));
    QObject::connect(&ultp,SIGNAL(back_main()),&w,SLOT(receive_show()));
    QObject::connect(&vibp,SIGNAL(back_main()),&w,SLOT(receive_show()));
    QObject::connect(&sf6p,SIGNAL(back_main()),&w,SLOT(receive_show()));



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
