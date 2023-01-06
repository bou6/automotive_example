#include <stdio.h>
#include <stdlib.h>
#include "Rte.h"
#include "Dem.h"
#include <unistd.h>

char door_menu()
{
    char in;
    printf("***********************************\n"); 
    printf("******** Door main app ************\n"); 
    printf("***********************************\n"); 
    printf("MENU\n"); 
    printf("***********************************\n"); 
    printf("1-Close door\n"); 
    printf("2-Open Door \n"); 
    printf("3-Create defect \n"); 
    printf("4-Remove defect \n"); 
    printf("***********************************\n"); 
    Dem_GetEventStatus();
    printf("\n***********************************\n\n"); 
    scanf(" %c",&in);
    return in;
}

void door_handle_input(char input)
{
    switch (input)
    {
        case '1':
        case '2':
            break;
        case '3':
            break;
        case '4':
            break;
        default:
            break;
    }
}

int main()
{
    while (1)
    {
        char input = door_menu();
        door_handle_input(input);
    }
}