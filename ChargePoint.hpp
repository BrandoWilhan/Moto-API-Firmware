#ifndef _CP_
#define _CP_

#include <iostream>
#include "Battery.hpp"

using namespace std;

const bool CHARGING = true;


class ChargePoint{

private:
    
    bool state = IDLE; //charging = true, idle = false

public:
    
    Battery *battery;
    
    ChargePoint(){
        this->battery = new Battery();
    }
    void setState(bool state){ this->state = state; }
    bool getState() const { return state; }
    
    
};

#endif