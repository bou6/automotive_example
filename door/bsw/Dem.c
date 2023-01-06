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
            break;

        case DEM_EVENT_STATUS_FAILED:
            currentEvent_ptr->status_en = DEM_EVENT_STATUS_FAILED;
            break;

        default:
            break;
    }

    return 0;

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