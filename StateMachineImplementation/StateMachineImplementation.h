#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef SMI_H
#define SMI_H

#define Max_String_Size 1000
#define Max_Data_Size 150

typedef enum
{
	STATE_MACHINE_NOT_FINISHED = 0,
	STATE_MACHINE_FINISHED_WITH_ERRORS=1,
	STATE_MACHINE_FINISHED_WITH_NO_ERRORS = 2

}State_Machine_Return_Type;

State_Machine_Return_Type parse(uint8_t ch);

typedef struct
{
	char string[Max_Data_Size][Max_Data_Size + 1]; //+1 because of the endline character
	bool ok;
	int lineCount;

}StateMachineStructure;

extern StateMachineStructure stateMachineStructure;

//uint8_t parse(char ch);



#endif