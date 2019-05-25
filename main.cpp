#include "mainwindow.h"
#include <QApplication>
#include <QtSerialPort>

#include <QFile>

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

    QDateTime current_date_time =QDateTime::currentDateTime();///system time get
    QDir log_Dir_Path ("/root/DeviceMonitorLog");
    QFile log_file_path ("/root/DeviceMonitorLog/Log.txt"); ///default log path

    QString create_success = "------Log File Create Success!------\n";
    QString open_application = "Application start running at:"+current_date_time.toString("yyyy.MM.dd hh:mm:ss.zzz")+"\n";

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


    QString currentDir = log_Dir_Path.currentPath();
   //if filePath not exist , create it
    if(!log_Dir_Path.exists())
    {
        qDebug()<<"path not exist"<<endl;
        log_Dir_Path.mkpath("/root/DeviceMonitorLog");
    }
   QFile *tempFile = new QFile;
   //set progream running path under filePath
   log_Dir_Path.setCurrent("/root/DeviceMonitorLog");
   qDebug()<<log_Dir_Path.currentPath();
   //chech if filePath exist file named fileName,if yes ......
   if(tempFile->exists("/root/DeviceMonitorLog"))
   {
        qDebug()<<"file exist";
   }
   //create log file if not exist
   QFileInfo fileinfo(log_file_path);
   if(!(fileinfo.exists()))
   {
       log_file_path.open(QIODevice::WriteOnly|QIODevice::Text);
       log_file_path.close();
       log_file_path.open(QIODevice::ReadWrite);
       log_file_path.write(create_success.toUtf8());
       log_file_path.close();
   }
   else//write app start log
   {                        //RW mode           add to end mode     text mode
       log_file_path.open(QIODevice::ReadWrite|QIODevice::Append|QIODevice::Text);
       log_file_path.write(open_application.toUtf8());
       log_file_path.close();
   }


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
