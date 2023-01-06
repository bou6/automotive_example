#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Rte.h"

void light_update_status()
{
    char door_status;
    printf("%c\n", door_status);
}

int main()
{
    
    while (1)
    {
        light_update_status();
        sleep(1);
    }
}