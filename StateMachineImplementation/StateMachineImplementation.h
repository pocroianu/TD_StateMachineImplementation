#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef SMI_H
#define SMI_H

#define Max_String_Size 40000
#define Max_Data_Size 150
#define Max_String_Count 100


char *filePointer;
//In here we will store the state.
static uint32_t state = 0;

void printStateMachineData();

typedef enum
{
	STATE_MACHINE_NOT_FINISHED = 0,
	STATE_MACHINE_FINISHED_WITH_ERRORS=1,
	STATE_MACHINE_FINISHED_SUCCESFULLY = 2

}State_Machine_Return_Type;

State_Machine_Return_Type parse();

typedef struct
{
	char content[Max_Data_Size][Max_Data_Size + 1]; //+1 because of the endline character

}StateMachineStructure;


#endif