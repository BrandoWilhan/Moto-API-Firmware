#include "moto.hpp"
#include "etb.hpp"

void Battery::hostAttach(ControlBattery *tipo)
{
    host = tipo;
}

void Battery::hostDetach()
{
    host = NULL;
}

ControlBattery* Battery::getHost()
{
    return host;
}