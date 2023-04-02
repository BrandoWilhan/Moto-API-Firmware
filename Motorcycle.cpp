#include "Motorcycle.hpp"


Moto::Moto(string plate){
    this->plate = plate;
    this->battery = new Battery();
}

void Moto::turnOn(){
    if(battery->getSoc() != 0 )
        state = ON;
}

void Moto::showParameters(){
    cout << "----------------------------------" << endl;
    cout << "|Motorcycle plate: " << plate << "       |"<< endl;
    cout << "|Speed: " << speed << "                  |"<< endl;
    cout << "|Attached battery: " << battery->getUid() << "           |"<< endl;
    cout << "|Motorcycle battery SoC: " << battery->getSoc() << " |"<< endl;
    cout << "----------------------------------" << endl;
}

void Moto::accelerate(int time){
    cout << "ACCELERATING" << endl;
    
    float soc;
    
    for(int i = 0; i < time; i++){
        if(soc > 0 && state){ 
            //state == on or standby  
            showParameters();

            soc = battery->getSoc();
            soc += -0.01 -(speed/MAX_SPEED)*(speed/MAX_SPEED)*0.05;
            battery->setSoc(soc);
            speed += 0.2;
        }
        else
            turnOff();
    }
}

void Moto::brake(int time){
    float soc;

    cout << "BRAKING" << endl;

    if(this->state){
        for(int i = 0; i < time; i++){
            showParameters();
            
            soc = battery->getSoc();
            soc += -0.01 -(speed/MAX_SPEED)*(speed/MAX_SPEED)*0.05;
            battery->setSoc(soc);
            speed -= 2;
        }
    }
    else
        turnOff();
}

void Moto::attachBattery(int uid, float soc){
    Battery *battery = new Battery(uid, soc);
    this->battery = battery;
    this->battery->hostAttach(this);
    this->battery->setState(ATTACHED);
    
}

void Moto::detachBattery(int uid){
    if(uid == this->battery->getUid()){
        this->battery->hostDetach();
        this->battery->setSoc(0);
        this->battery->setState(IDLE);
        this->battery->setUid(0);
        turnOff();
    }
    else
        cout << "UID não encontrado" << endl;
}

Battery * Moto::getBattery(){
    return this->battery;
}