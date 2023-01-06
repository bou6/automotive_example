#ifndef COMM_H
#define COMM_H
#include <stdint.h>
// Includes
#ifdef __cplusplus
extern "C"
{
#endif

/////////////////////////////////////////////
/////////// Functions declaration ///////////
/////////////////////////////////////////////
char Comm_receive();
int Comm_init();

#ifdef __cplusplus
}
#endif
#endif