#include "Motorcycle.hpp"
#include "ChangeBatteryStation.hpp"
#include "ControlBattery.hpp"

int main(){
    Moto moto("1234567");
    ChangeBatteryStation station(0);

    moto.attachBattery(555, 75); //uid e carga
    moto.turnOn();
    
    //moto acelera por 180 segundos e freia por 10 segundos
    moto.accelerate(180);
    moto.brake(10);
    station.attachBattery(123, 50); //uid e carga

    //moto acelera por 120 segundos e freia por 10 segundos
    moto.accelerate(120);
    moto.brake(12);
    
    return 0;
}