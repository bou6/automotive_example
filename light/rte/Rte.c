#include "Rte.h"
#include "Comm.h"

char Rte_receiveNotif()
{
    return Comm_receive();
}

int Rte_commInit()
{
    return Comm_init();
}