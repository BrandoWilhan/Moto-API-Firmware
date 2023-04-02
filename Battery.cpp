#include "Motorcycle.hpp"
#include "ChangeBatteryStation.hpp"

Battery::Battery(){

}

Battery::Battery(int uid){
    this->uid = uid;
}

Battery::Battery(int uid, float soc){
    this->uid = uid;
    this->soc = soc;
}

void Battery::hostAttach(ControlBattery *tipo){
    host = tipo;
}

void Battery::hostDetach(){
    host = NULL;
}

ControlBattery* Battery::getHost(){
    return host;
}