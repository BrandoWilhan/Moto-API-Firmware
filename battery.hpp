#ifndef _BATTERY_
#define _BATTERY_

#include <iostream>
#include <string>

using namespace std;

class ControlBattery;

bool const ATTACHED = true;

class Battery
{
    long long int uid;              //identificador da bateria
    float soc;                      //estado de carga
    ControlBattery *host = NULL;    //moto ou estacao de troca de bateria
    bool state;                     //idle = false ou attached = true

public:

    void setUid(long long int uid){ this->uid = uid; }
    long long int getUid() const { return uid; }
    void setSoc(float soc){ this->soc = soc; }
    float getSoc() const { return soc; }
    void setState(bool state){ this->state = state; }
    bool getState() const { return state; }
    void hostAttach(ControlBattery* );          //OK
    void hostDetach();                          //OK
    ControlBattery * getHost();                 //OK
};

#endif
