#ifndef SETTING_VALUE_H
#define SETTING_VALUE_H

#include <QObject>

#include <QSharedDataPointer>

class Setting_valueData;

class Setting_value
{
public:
    //namespace ssss{
    static int R_RATE_TEMP;
    static int R_RATE_HUMI;
    static int R_RATE_ULT;
    static int R_RATE_TEV;
    static int R_RATE_VIB;
    static int R_RATE_SF6;


    ////set
    static bool UNIT_TEMP;
    static bool MAIN_SET;
    static bool PAGE_MAIN;


    Setting_value();
    Setting_value(const Setting_value &);
    Setting_value &operator=(const Setting_value &);
    ~Setting_value();

    static void Temp_Statue_Set(bool swt);
    static bool Temp_Statue_get();
    static void R_RATE_TEMP_SET(int ipt);

private:
    QSharedDataPointer<Setting_valueData> data;
};

#endif // SETTING_VALUE_H
