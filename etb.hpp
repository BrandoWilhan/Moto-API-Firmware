#ifndef _ETB_
#define _ETB_

#include "cp.hpp"
#include "controlabateria.hpp"


class ETB : public ControlBattery
{
private:
    long int uid;       //identificador da estaçao de troca de bateria
    CP cp[6];           //max 6 charge points
public:
    
    void setUid(long int uid){ this->uid = uid; }
    long int getUid() const { return uid; }
    CP getCp(int n) const { return cp[n]; }
    void attachBattery(Battery);                //OK
    void detachBattery(int);                    //OK
    void setCharge(int n);                      //OK
    void setDischarge(int n);                   //OK
    int totalBatteries();                       //OK
    int totalBatteriesCharging();               //OK
    float timeRestCharge(int);                  //OK

};

#endif