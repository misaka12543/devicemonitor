#include "mainwindow.h"
#include <QApplication>
#include <QtSerialPort>

#include <QFile>

//key page
#include "mainwindow_list_ver.h"
#include "setting_page.h"
#include "setting_value.h"

//log page
#include "show_log_page.h"

//sensors
#include "ult_monitor_page.h"
#include "sf6_monitor_page.h"
#include "vib_monitor_page.h"
#include "temp_monitor_page.h"
#include "tev_monitor_page.h"
#include "humi_monitor_page.h"
#include "show_log_page.h"

extern int app_version ;
extern double app_version_D ;

int app_version = 3;
double app_version_D = app_version*0.1;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ///system time get
    QDateTime current_date_time =QDateTime::currentDateTime();

    ///log dir
    QDir log_Dir_Path ("/root/DeviceMonitorLog");
    ///detail log dir
    QDir log_detail_dir ("/root/DeviceMonitorLog/Log");

    ///default log path
    QFile log_file_path ("/root/DeviceMonitorLog/Log.txt");

    ///humi log path
    QFile humi_log("/root/DeviceMonitorLog/Log/humi_log");
    ///sf6 log path
    QFile sf6_log("/root/DeviceMonitorLog/Log/sf6_log");
    ///temp log path
    QFile temp_log("/root/DeviceMonitorLog/Log/temp_log");
    ///vib log path
    QFile vib_log("/root/DeviceMonitorLog/Log/vib_log");
    ///tev log path
    QFile tev_log("/root/DeviceMonitorLog/Log/tev_log");
    ///ult log path
    QFile ult_log("/root/DeviceMonitorLog/Log/ult_log");
    ///log log path
    QFile log_log("/root/DeviceMonitorLog/Log/log_log");
    ///main log path
    QFile log_main("/root/DeviceMonitorLog/Log.txt");
    ///
    QFile setting_value("/root/DeviceMonitorLog/Settings.val");

    QString create_success = "------Log File Create Success!------\n";
    QString open_application = "Application start running at:"+current_date_time.toString("yyyy.MM.dd hh:mm:ss.zzz")+"\n";

    MainWindow w;
    MainWindow_list_ver wlv;

    setting_page setp;

    show_log_page logpg;

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

    QObject::connect(&w,SIGNAL(log_show()),&logpg,SLOT(receive_show()));
    QObject::connect(&w,SIGNAL(humidetail_show()),&humip,SLOT(receive_show()));
    QObject::connect(&w,SIGNAL(tempsdetail_show()),&tempp,SLOT(receive_show()));
    QObject::connect(&w,SIGNAL(tevdetail_show()),&tevp,SLOT(receive_show()));
    QObject::connect(&w,SIGNAL(ultdetil_show()),&ultp,SLOT(receive_show()));
    QObject::connect(&w,SIGNAL(vibdetail_show()),&vibp,SLOT(receive_show()));
    QObject::connect(&w,SIGNAL(sf6detail_show()),&sf6p,SLOT(receive_show()));


    QObject::connect(&wlv,SIGNAL(back_main()),&w,SLOT(receive_show()));

    QObject::connect(&setp,SIGNAL(back_main()),&w,SLOT(receive_show()));

    QObject::connect(&logpg,SIGNAL(back_main()),&w,SLOT(receive_show()));

    QObject::connect(&humip,SIGNAL(back_main()),&w,SLOT(receive_show()));
    QObject::connect(&tempp,SIGNAL(back_main()),&w,SLOT(receive_show()));
    QObject::connect(&tevp,SIGNAL(back_main()),&w,SLOT(receive_show()));
    QObject::connect(&ultp,SIGNAL(back_main()),&w,SLOT(receive_show()));
    QObject::connect(&vibp,SIGNAL(back_main()),&w,SLOT(receive_show()));
    QObject::connect(&sf6p,SIGNAL(back_main()),&w,SLOT(receive_show()));

    QObject::connect(&ultp,SIGNAL(setting_show()),&setp,SLOT(receive_show()));


    QString currentDir = log_Dir_Path.currentPath();
    //create log dir
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

   //create log detail dir
   if(!log_detail_dir.exists())
   {
      qDebug()<<"path not exist"<<endl;
      log_detail_dir.mkpath("/root/DeviceMonitorLog/Log");
   }
  QFile *tempFile2 = new QFile;
  //set progream running path under filePath
  log_detail_dir.setCurrent("/root/DeviceMonitorLog/Log");
  //chech if filePath exist file named fileName,if yes ......
  if(tempFile2->exists("/root/DeviceMonitorLog/Log"))
  {
       qDebug()<<"file exist";
  }



   //create log file
   //create log file if not exist
   QFileInfo fileinfo_log(log_file_path);
   if(!(fileinfo_log.exists()))
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

   //create detail log files
   QFileInfo fileinfo_humi(humi_log);
   QFileInfo fileinfo_tev(tev_log);
   QFileInfo fileinfo_sf6(sf6_log);
   QFileInfo fileinfo_vib(vib_log);
   QFileInfo fileinfo_ult(ult_log);
   QFileInfo fileinfo_temp(temp_log);
   if(!fileinfo_humi.exists())
   {
       humi_log.open(QIODevice::WriteOnly|QIODevice::Text);
       humi_log.close();
       humi_log.open(QIODevice::ReadWrite);
       humi_log.write(create_success.toUtf8());
       humi_log.close();
   }
   else
   {
       //do nothing
   }
   if(!fileinfo_tev.exists())
   {
       tev_log.open(QIODevice::WriteOnly|QIODevice::Text);
       tev_log.close();
       tev_log.open(QIODevice::ReadWrite);
       tev_log.write(create_success.toUtf8());
       tev_log.close();
   }
   else
   {
       //do nothing
   }
   if(!fileinfo_sf6.exists())
   {
       sf6_log.open(QIODevice::WriteOnly|QIODevice::Text);
       sf6_log.close();
       sf6_log.open(QIODevice::ReadWrite);
       sf6_log.write(create_success.toUtf8());
       sf6_log.close();
   }
   else
   {
       //do nothing
   }
   if(!fileinfo_vib.exists())
   {
       vib_log.open(QIODevice::WriteOnly|QIODevice::Text);
       vib_log.close();
       vib_log.open(QIODevice::ReadWrite);
       vib_log.write(create_success.toUtf8());
       vib_log.close();
   }
   else
   {
       //do nothing
   }
   if(!fileinfo_ult.exists())
   {
       ult_log.open(QIODevice::WriteOnly|QIODevice::Text);
       ult_log.close();
       ult_log.open(QIODevice::ReadWrite);
       ult_log.write(create_success.toUtf8());
       ult_log.close();
   }
   else
   {
       //do nothing
   }
   if(!fileinfo_temp.exists())
   {
       temp_log.open(QIODevice::WriteOnly|QIODevice::Text);
       temp_log.close();
       temp_log.open(QIODevice::ReadWrite);
       temp_log.write(create_success.toUtf8());
       temp_log.close();
   }
   else
   {
       //do nothing
   }

   QFileInfo setting_value_file(setting_value);
   if(!setting_value_file.exists())
   {

       setting_value.open(QIODevice::WriteOnly|QIODevice::Text);
       setting_value.close();
       setting_value.open(QIODevice::ReadWrite);
       int x = all_value.R_RATE_ULT;
       setting_value.write("");
       setting_value.close();
   }
   else
   {

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
