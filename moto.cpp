#include "moto.hpp"

bool const IDLE = false;

void Moto::turnOn()
{
    if(battery.getSoc() != 0 )
        state = ON;
}

void Moto::accelerate(int time)
{
    float soc = battery.getSoc();
    
    cout << "vrum" << endl;

    if(soc <= 0)
    {
        turnOff();
    }
    
        for(int i = 0; i < time; i++)
        {
            if(soc > 0 && state) //state == on or standby  
            {
                soc += -0.01 -(speed/MAX_SPEED)*(speed/MAX_SPEED)*0.05;
                battery.setSoc(soc);
                speed += 0.2;
                soc = battery.getSoc();
            }
            else
                turnOff();

            if(time%10 == 0 && soc > 0)
            {
                cout << "Motorcycle plate: " << plate << endl;
                cout << "Speed: " << speed << endl;
                cout << "Attached battery: " << battery.getUid() << endl;
                cout << "Motorcycle battery SoC: " << battery.getSoc() << "\%" << endl;
            }
        }
}

void Moto::brake(int time)
{
    float soc;

    cout << "freando" << endl;

    if(state)
    {
        for(int i = 0; i < time; i++)
        {
            soc = battery.getSoc();
            soc += -0.01 -(speed/MAX_SPEED)*(speed/MAX_SPEED)*0.05;
            battery.setSoc(soc);
            speed -= 2;
        }
    }
}

void Moto::attachBattery(Battery battery)
{
    this->battery = battery;
    this->battery.hostAttach(this);
    this->battery.setState(ATTACHED);
}

void Moto::detachBattery()
{
    this->battery.hostDetach();
    this->battery.setSoc(0);
    this->battery.setState(IDLE);
    this->battery.setUid(0);
}