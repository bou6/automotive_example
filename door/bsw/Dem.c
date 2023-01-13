#include <stdio.h>
#include "Dem.h"
#include "Nvm.h"

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
            if (currentEvent_ptr->curr_counter > 0)
                currentEvent_ptr->curr_counter--;
            //check whether the threshold are reached
            if (currentEvent_ptr->curr_counter == 0)
                currentEvent_ptr->status_en = DEM_EVENT_STATUS_PASSED;    
            break;
        
        case DEM_EVENT_STATUS_PREFAILED:
            if (currentEvent_ptr->curr_counter < DEM_EVENT_THRESHOLD)
                currentEvent_ptr->curr_counter++;
            //check whether the threshold are reached
            if (currentEvent_ptr->curr_counter == DEM_EVENT_THRESHOLD)
                currentEvent_ptr->status_en = DEM_EVENT_STATUS_FAILED;    
            break;

        case DEM_EVENT_STATUS_PASSED:
            currentEvent_ptr->status_en = DEM_EVENT_STATUS_PASSED;
            // set the counter to threshold
            currentEvent_ptr->curr_counter= DEM_EVENT_THRESHOLD;
            break;

        case DEM_EVENT_STATUS_FAILED:
            currentEvent_ptr->status_en = DEM_EVENT_STATUS_FAILED;
            // set the counter to threshold
            currentEvent_ptr->curr_counter= DEM_EVENT_THRESHOLD;
            break;

        default:
            break;
    }

    // write the counter value in the Nvm
    ret = Nvm_WriteBlock((int)(id), currentEvent_ptr->curr_counter);

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