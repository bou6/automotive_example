#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Rte.h"

void light_update_status()
{
    char door_status= Rte_receiveNotif();
    switch (door_status)
    {
        case '1':
            printf("ligh status : off \n");
            break;
        case '2':
            printf("ligh status : on \n");
            break;
        default:
            break;
    }
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