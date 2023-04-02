#include "ChangeBatteryStation.hpp"

using namespace std;

ChangeBatteryStation::ChangeBatteryStation(long int uid){
    this->uid = uid;
}


void ChangeBatteryStation::showParameters(){
    for(int i = 0; i < 6; i++){
        cout << "----------------"<< endl;
        cout << "Station UID: "<< this->uid << endl;
        cout << "Charge Point: "<< i;
        if(this->chargePoint[i].getState())
           cout << " CHARGING" << endl;
        else
           cout << " IDLE" << endl;
        cout << "Battery SOC: "<< this->chargePoint[i].battery->getSoc() << endl;
        cout << "----------------"<< endl;
    }

}


void ChangeBatteryStation::attachBattery(int uid, float soc){
    for(int i = 0; i < 6;i++)
        if(chargePoint[i].battery->getHost() == NULL){ 
            //se não esta carregando
            Battery * battery = new Battery(uid, soc);                                                          // e nao tem host
            chargePoint[i].battery = battery;
            chargePoint[i].battery->hostAttach(this);
            chargePoint[i].setState(CHARGING);
            cout << "battery allowed in charge point number:" << i << endl;
            showParameters();
            break;
        }
}

void ChangeBatteryStation::detachBattery(int uid){
    for(int i; i < 6; i++)
        if(chargePoint[i].battery->getUid() == uid){   
            chargePoint[i].battery->hostDetach();
            chargePoint[i].setState(IDLE);
        }
    else
        cout << "UID não encontrado" << endl;
}

void ChangeBatteryStation::setCharge(int n){
    if(n <= 5 && n >= 0 && chargePoint[n].getState()){   
        int i;

        chargePoint[n].setState(CHARGING);
        chargePoint[n].battery->setState(ATTACHED);
        i = chargePoint[n].battery->getSoc();
        
        while(i < 100){
            showParameters();
            i += 0.05;
        }
    }
}

void ChangeBatteryStation::setDischarge(int n){
    if(n <= 5 && n >= 0)
    {  
        chargePoint[n].setState(IDLE);
    }
}

int ChangeBatteryStation::totalBatteries(){
    int count = 0;
    
    for(int i = 0; i < 6; i++){
        if(chargePoint[i].battery->getHost() != NULL)
            count++;
    }
    
    return count;
}

int ChangeBatteryStation::totalBatteriesCharging(){
    int count = 0;
    
    for(int i = 0; i < 6; i++){
        if(chargePoint[i].getState() == CHARGING)
            count++;
    }
    
    return count;
}

float ChangeBatteryStation::timeRestCharge(int n){
    float soc;
    float time;

    if(n <= 5 && n >= 0){
        soc = chargePoint[n].battery->getSoc();
        time = (100 - soc)/0.05;
    }

    return time;
}