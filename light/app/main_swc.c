#include <stdio.h>
#include <stdlib.h>
#include "Rte.h"

void light_update_status()
{
    char door_status= Rte_receiveNotif();
    printf("%c\n", door_status);
}

int main()
{
    Rte_commInit();
    
    while (1)
    {
        light_update_status();
        sleep(1);
    }
}