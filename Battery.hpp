#ifndef _BATTERY_
#define _BATTERY_

#include <iostream>
#include <string>

using namespace std;

class ControlBattery;

bool const ATTACHED = true;
bool const IDLE = false;

class Battery{
    
private:

    int uid;              //identificador da bateria
    float soc;                      //estado de carga
    ControlBattery *host = NULL;    //moto ou estacao de troca de bateria
    bool state = IDLE;                     //idle = false ou attached = true

public:

    Battery();
    Battery(int);
    Battery(int, float);
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
