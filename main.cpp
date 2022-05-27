#include "moto.hpp"
#include "etb.hpp"
#include "controlabateria.hpp"

int main()
{
    Battery battery;
    Moto moto;

    moto.setPlate("6514897");
    battery.setUid(747);
    battery.setSoc(85);
    moto.attachBattery(battery);
    moto.turnOn();
    
    for (int i = 0; i < 6; i++)
    {
        moto.accelerate(180);
        moto.brake(10);
    }

    for (int i = 0; i < 4; i++)
    {
        moto.accelerate(120);
        moto.brake(12);
    }
    

    return 0;
}