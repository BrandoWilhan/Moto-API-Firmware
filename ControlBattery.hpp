#ifndef _CONTROL_
#define _CONTROL_

#include "Battery.hpp"

class ControlBattery{
    
public:
    
    virtual ~ControlBattery(){ }
    virtual void attachBattery(Battery*) = 0;
    virtual void detachBattery(int) = 0;
};


#endif