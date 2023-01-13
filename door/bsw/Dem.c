#include <stdio.h>
#include "Dem.h"

Dem_EventStruct g_eventArray_ast[] =
{
    {TEST_EVENT_ID_1,DEM_EVENT_STATUS_PASSED ,0},

};

/*
 **********************************************************************************************************************
 * Functions declaration
 **********************************************************************************************************************
*/
int Dem_SetEventStatus(const Dem_EventIdType id, const Dem_EventStatusType status)
{
    int index;
    int array_size = sizeof(g_eventArray_ast)/ sizeof(Dem_EventStruct);
    Dem_EventStruct* currentEvent_ptr;
    int ret=0;

    for (index=0; index < array_size; index++)
    {
        if (g_eventArray_ast[index].id == id)
        {
            currentEvent_ptr= &g_eventArray_ast[index];
            break;
        }
    }

    if (index>=array_size)
    {
        // the id is not found
        return -1;
    }

    switch (status)
    {
        case DEM_EVENT_STATUS_PREPASSED:
            //< add here
            break;
        
        case DEM_EVENT_STATUS_PREFAILED:
            //< add here
            break;

        case DEM_EVENT_STATUS_PASSED:
            //< add here
            break;

        case DEM_EVENT_STATUS_FAILED:
            //< add here
            break;

        default:
            break;
    }

    return ret;

}

void Dem_GetEventStatus()
{
    int index;
    int array_size = sizeof(g_eventArray_ast)/ sizeof(Dem_EventStruct);
    Dem_EventStruct* currentEvent_ptr;

    for (index=0; index < array_size; index++)
    {
        printf("Id=%d, status=%d, counter = %d", g_eventArray_ast[index].id, g_eventArray_ast[index].status_en, g_eventArray_ast[index].curr_counter);
    }

}

void Dem_MainFunction()
{
    char in;
    printf("***********************************\n"); 
    printf("**** Diagnostic creation/Removal **\n"); 
    printf("***********************************\n"); 
    printf("Diagnostic MENU\n"); 
    printf("***********************************\n"); 
    printf("1-Create Defect (DTC = 0x01)\n"); 
    printf("2-Remove Defect (DTC = 0x02)\n"); 
    printf("***********************************\n"); 
    Dem_GetEventStatus();
    printf("\n***********************************\n\n"); 
    scanf(" %c",&in);

    switch (in)
    {
    case '1':
        Dem_SetEventStatus(TEST_EVENT_ID_1, DEM_EVENT_STATUS_PREFAILED);
        break;

    case '2':
        Dem_SetEventStatus(TEST_EVENT_ID_1, DEM_EVENT_STATUS_PREFAILED);
        break;
    
    default:
        break;
    }
}