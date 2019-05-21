#ifndef SETTING_VALUE_H
#define SETTING_VALUE_H

#include <QObject>

#include <QSharedDataPointer>

extern int R_RATE_TEMP;
extern int R_RATE_HUMI;
extern int R_RATE_ULT;
extern int R_RATE_TEV;
extern int R_RATE_VIB;
extern int R_RATE_SF6;


////set
extern bool UNIT_TEMP;
extern bool MAIN_SET;
extern bool PAGE_MAIN;

class Setting_valueData;

class Setting_value
{
public:
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
