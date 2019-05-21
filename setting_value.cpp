    #include "setting_value.h"

class Setting_valueData : public QSharedData
{
public:

//what's this ? I forget it ...
};

int R_RATE_TEMP=5;

int R_RATE_HUMI=5;

int R_RATE_ULT=5;

int R_RATE_TEV=5;

int R_RATE_VIB=5;

int R_RATE_SF6=50;





 ///set

bool UNIT_TEMP=false;

bool MAIN_SET=true;
bool PAGE_MAIN=false;
Setting_value::Setting_value() : data(new Setting_valueData)
{


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
    R_RATE_TEMP=ipt;
}
void Setting_value::Temp_Statue_Set(bool swt)
{
    UNIT_TEMP=swt;
}
bool Setting_value::Temp_Statue_get()
{

    return UNIT_TEMP;
}
