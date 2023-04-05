#ifndef _ETB_
#define _ETB_

#include "ChargePoint.hpp"
#include "ControlBattery.hpp"


class ChangeBatteryStation : public ControlBattery{

private:

    long int uid;       //identificador da estaçao de troca de bateria
    ChargePoint chargePoint[6];   //max 6 charge points
    
public:
    
    ChangeBatteryStation(long int);
    void setUid(long int uid){ this->uid = uid; }
    long int getUid() const { return uid; }
    ChargePoint getChargePoint(int n) const { return chargePoint[n]; }
    void attachBattery(Battery*);                //OK
    void detachBattery(int);                    //OK
    void setCharge(int n);                      //OK
    void setDischarge(int n);                   //OK
    int totalBatteries();                       //OK
    int totalBatteriesCharging();               //OK
    float timeRestCharge(int);                  //OK
    void showParameters();

};

#endif