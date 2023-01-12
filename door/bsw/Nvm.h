#ifndef NVM_H
#define NVM_H
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

/*
 **********************************************************************************************************************
 * typedefs
 **********************************************************************************************************************
*/

/*
 **********************************************************************************************************************
 * Functions declaration
 **********************************************************************************************************************
*/
int Nvm_WriteBlock(int blockId, int value);
int Nvm_ReadBlock(int blockId, int* value_ptr);

#ifdef __cplusplus
}
#endif
#endif

