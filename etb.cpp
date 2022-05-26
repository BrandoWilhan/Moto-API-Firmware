#include "etb.hpp"


void ETB::attachBattery(Battery battery)
{
    for (int i = 0; i < 6; i++)
    {
        if(!(cp[i].getState()) && (cp[i].battery.getHost() == NULL)) //se nao esta carregando
        {                                                            // e nao tem host
            cp[i].battery = battery;
            break;
        }
        
        cp[i].battery.hostAttach(this);
        cout << "battery allowed in charge point number:" << i << endl;
    }
}

void ETB::detachBattery(int n)
{
    if(n <= 5 && n >= 0)
    {   
        cp[n].battery.hostDetach();
        cp[n].battery.setState(IDLE);
    }
    else
        cout << "charge point invalido, tente novamente" << endl;
}

void ETB::setCharge(int n)
{
    if(n <= 5 && n >= 0 && cp[n].getState())
    {   
        int i;

        cp[n].setState(CHARGING);
        cp[n].battery.setState(ATTACHED);
        i = cp[n].battery.getSoc();
        
        while(i < 100)
        {
            i += 0.05;
        }
    }
}

void ETB::setDischarge(int n)
{
    if(n <= 5 && n >= 0)
    {  
        cp[n].setState(IDLE);
    }
}

int ETB::totalBatteries()
{
    int count = 0;
    
    for(int i = 0; i < 6; i++)
    {
        if(cp[i].battery.getHost() != NULL)
            count++;
    }
    
    return count;
}

int ETB::totalBatteriesCharging()
{
    int count = 0;
    
    for(int i = 0; i < 6; i++)
    {
        if(cp[i].getState() == CHARGING)
            count++;
    }
    
    return count;
}

float ETB::timeRestCharge(int n)
{
    float soc;
    float time;

    if(n <= 5 && n >= 0)
    {
        soc = cp[n].battery.getSoc();
        time = (100 - soc)/0.05;
    }

    return time;
}