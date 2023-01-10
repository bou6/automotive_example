#include "Nvm.h"
#include <stdlib.h>
#include <stdio.h>

int Nvm_WriteBlock(int blockId, int value)
{
    char path[20];
    FILE *fptr;

    sprintf(path, "block_%d", value);

     if ((fptr = fopen(path,"w+")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }
    // here write 
   fclose(fptr); 


    return 0;
}

int Nvm_ReadBlock(int blockId);
