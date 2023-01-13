#include <stdio.h>
#include "Dcm.h"
#include "diag_swc.h"

/*
 **********************************************************************************************************************
 * Functions definition
 **********************************************************************************************************************
*/
void Dcm_MainFunction()
{
    char in;
    printf("\n*********************************\n"); 
    printf("***** Diagnostic main *************\n"); 
    printf("***********************************\n"); 
    printf("Diagnostic MENU\n"); 
    printf("***********************************\n"); 
    printf("1-Read DTCs (0x19)\n"); 
    printf("2-Change Diagnostic session (0x10)\n"); 
    printf("\n***********************************\n\n"); 
    scanf(" %c",&in);

    switch (in)
    {
    case '1':
        Diag_ReadDtcs();
        break;

    case '2':
        break;
    
    default:
        break;
    }
}