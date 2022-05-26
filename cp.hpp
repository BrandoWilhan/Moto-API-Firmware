#ifndef _CP_
#define _CP_

#include <iostream>
#include "battery.hpp"

using namespace std;

const bool CHARGING = true;
const bool IDLE = false;

class CP
{
private:
    
    bool state = false; //charging = true, idle = false

public:
    
    Battery battery;
    void setState(bool state){ this->state = state; }
    bool getState() const { return state; }
  
};

#endif