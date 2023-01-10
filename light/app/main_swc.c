#include <stdio.h>
#include <stdlib.h>
#include "Rte.h"

void light_update_status()
{
    char door_status= Rte_receiveNotif();
    printf("%c\n", door_status);
    switch (door_status)
    {
        case '1':
            printf("ligh status : off \n");
        case '2':
            printf("ligh status : on \n");
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