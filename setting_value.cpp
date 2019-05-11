    #include "setting_value.h"

class Setting_valueData : public QSharedData
{
public:


};

Setting_value::Setting_value() : data(new Setting_valueData)
{
//    R_RATE_TEMP=5;

//    R_RATE_HUMI=5;

//    R_RATE_ULT=5;

//    R_RATE_TEV=5;

//    R_RATE_VIB=5;

//    R_RATE_SF6=50;





//    ///set

//    UNIT_TEMP=false;

//    MAIN_SET=true;
//    PAGE_MAIN=false;

}

Setting_value::Setting_value(const Setting_value &rhs) : data(rhs.data)
{

}

Setting_value &Setting_value::operator=(const Setting_value &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

Setting_value::~Setting_value()
{

}
void Setting_value::R_RATE_TEMP_SET(int ipt)
{
    Setting_value::R_RATE_TEMP=ipt;
}
void Setting_value::Temp_Statue_Set(bool swt)
{
    Setting_value::UNIT_TEMP=swt;
}
bool Setting_value::Temp_Statue_get()
{

    return Setting_value::UNIT_TEMP;
}
