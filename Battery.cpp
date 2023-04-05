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

void Battery::getHostName(){
    if(instanceof<Moto>(host) && host != NULL){
        Moto *ptrMoto = dynamic_cast<Moto*>(host);
        cout << "Host Type: Moto \nHost Identifier: " << ptrMoto->getPlate() << endl;
    }
    else if(instanceof<ChangeBatteryStation>(host) && host != NULL){
        ChangeBatteryStation *ptrChangeBattery = dynamic_cast<ChangeBatteryStation*>(host);
        cout << "Host Type: ETB \nHost Identifier: " << ptrChangeBattery->getUid() << endl;
    }
    else
        cout << "IDLE" << endl;
}

