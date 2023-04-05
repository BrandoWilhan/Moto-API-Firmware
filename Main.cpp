#include "Motorcycle.hpp"
#include "ChangeBatteryStation.hpp"
#include "ControlBattery.hpp"

int main(){
    Moto moto("1234567");
    ChangeBatteryStation station(0);
    Battery battery(15, 75); //battery id e soc

    moto.attachBattery(&battery); //battery pointer
    moto.turnOn();
    
    //moto acelera por 180 segundos e freia por 10 segundos 10 vezes
    for(int i = 0; i < 10; i++){
        moto.accelerate(180);
        moto.brake(10);
    }    
        
    
    station.attachBattery(&battery); //battery pointer

    //moto acelera por 120 segundos e freia por 10 segundos 10 vezes
    for(int i = 0; i < 10; i++){
        moto.accelerate(120);
        moto.brake(12);
    } 

    return 0;
}