#ifndef _CONTROL_
#define _CONTROL_

#include "battery.hpp"

class ControlBattery
{
public:
    
    virtual ~ControlBattery(){ }
    virtual void attachBattery(Battery) = 0;
    virtual void detachBattery() = 0;
};


#endif