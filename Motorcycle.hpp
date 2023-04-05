#ifndef _MOTO_
#define _MOTO_

#include "ControlBattery.hpp"

bool const ON = true;
bool const STANDBY = false;
float const MAX_SPEED = 60;

class Moto : public ControlBattery {

private:
    
    bool state = STANDBY;             //on = true ou standby = false
    string plate;                     //placa da moto 7 caracteres alfanumericos
    float speed = 0;  
    Battery *battery;

public:

    Moto(string);

    inline string getState() const{ 
        return state ? "ON": "OFF";
    }

    Battery * getBattery();
    void setPlate(string plate){ this->plate = plate; }
    string getPlate() const { return plate; }
    float getSpeed() const { return speed; }
    void turnOn();
    void turnOff(){ state = STANDBY; }
    void accelerate(int);    //int time in seconds OK
    void brake(int);         //int time in seconds OK
    void attachBattery(Battery*);         //OK
    void detachBattery(int);                //OK
    void showParameters();

};

#endif

