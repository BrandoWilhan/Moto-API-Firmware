#include "moto.hpp"
#include "etb.hpp"

int main()
{
    Battery battery;
    Moto moto;

    battery.setUid(747);
    battery.setSoc(85);
    moto.attachBattery(battery);
    

    return 0;
}