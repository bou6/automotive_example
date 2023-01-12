#include "Nvm.h"
#include <stdlib.h>
#include <stdio.h>

int Nvm_WriteBlock(int blockId, int value)
{
    char path[20];
    FILE *fptr;

    sprintf(path, "block_%d", blockId);

    if ((fptr = fopen(path,"w")) == NULL){
        printf("Error! opening file");
        return -1;
    }

    fprintf(fptr, "%d", value);
    // here write 
    fclose(fptr); 

    return 0;
}

int Nvm_ReadBlock(int blockId, int* value_ptr)
{
    FILE *fptr;
    char path[20];

    if (value_ptr == NULL)
        return -1;

    sprintf(path, "block_%d", blockId);
    
    if ((fptr = fopen(path,"r")) == NULL){
        printf("Error! opening file");
        return -1;
    }
    fscanf(fptr, "%d", value_ptr);

    // here write 
    fclose(fptr);
    return 0;
}
