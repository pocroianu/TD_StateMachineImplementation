#include"StateMachineImplementation.h"
StateMachineStructure st;

State_Machine_Return_Type parse(uint8_t pch)
{
	//In here we will store the state.
	static uint32_t state = 0;


	switch (state)
	{
		case 0:
		{
			//CR
			if (pch == 0x0D)
			{	
				printf("state1\n");
				state = 1;
				pch++; //consumes the character
				
			}
			else
			{	
				state = 0;
				printf("state0\n");
				return STATE_MACHINE_FINISHED_WITH_NO_ERRORS;

			}
			break;
		}
	}

	return STATE_MACHINE_NOT_FINISHED;
}