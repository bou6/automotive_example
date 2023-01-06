#ifndef DEM_H
#define DEM_H
// Includes
#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif
/*
 **********************************************************************************************************************
 * Defines/Macros
 **********************************************************************************************************************
*/
#define DEM_EVENT_THRESHOLD (10)

/*
 **********************************************************************************************************************
 * typedefs
 **********************************************************************************************************************
*/
typedef uint16_t Dem_EventIdType;

/* test events Id */
#define TEST_EVENT_ID_1  (0x01)
#define TEST_EVENT_ID_2  (0x02)
#define TEST_EVENT_ID_3  (0x03)
#define TEST_EVENT_ID_4  (0x04)

/**
 * Event status
 */
typedef enum
{
    DEM_EVENT_STATUS_PASSED     =  0x00,   //Monitor reports qualified test result passed.
    DEM_EVENT_STATUS_FAILED     = 0x01,    //Monitor reports qualified test result failed.
    DEM_EVENT_STATUS_PREPASSED  = 0x02, //Monitor reports non-qualified test result pre-passed (debounced Dem-internally).
    DEM_EVENT_STATUS_PREFAILED  = 0x03, //Monitor reports non-qualified test result pre-failed (debounced Dem-internally).
}Dem_EventStatusType;

typedef struct 
{
    Dem_EventIdType id;
    Dem_EventStatusType status_en;
    int curr_counter;
}Dem_EventStruct;

/*
 **********************************************************************************************************************
 * Functions declaration
 **********************************************************************************************************************
*/
int Dem_SetEventStatus(Dem_EventIdType, Dem_EventStatusType);
void Dem_GetEventStatus();

#ifdef __cplusplus
}
#endif
#endif

