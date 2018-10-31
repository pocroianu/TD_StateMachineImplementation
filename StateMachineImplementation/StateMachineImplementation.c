#include"StateMachineImplementation.h"

void printError() {

	//printf("Error \n");
}

void printCurrentState() {
	printf("CurrentState : %d - Character : %d \n", state,*filePointer);
}


State_Machine_Return_Type parse()
{

	while (1) {

		switch (state)
		{
		case 0:
		{
			printCurrentState();

			if (*filePointer == 0x0D)
			{
				state = 1;
				filePointer++; //consumes the character

			}
			else
			{
				printError();
				return STATE_MACHINE_FINISHED_WITH_ERRORS;
			}

			break;
		}
		case 1:
		{
			printCurrentState();
			if (*filePointer == 0x0A)
			{

				state = 2;
				filePointer++;

			}
			else
			{

				printError();
				return STATE_MACHINE_FINISHED_WITH_ERRORS;
			}
			break;
		}

		case 2:
		{
			printCurrentState();
			if (*filePointer == '+')
			{
				state = 3;
				filePointer++;
			}
			else if (*filePointer == 'E' || *filePointer == 'e')
			{
				state = 8;
				filePointer++;
			}
			else if (*filePointer == 'O' || *filePointer == 'o')
			{
				state = 9;
				filePointer++;
			}
			else
			{
				printError();
				return STATE_MACHINE_FINISHED_WITH_ERRORS;
			}
			break;
		}
		case 3:
		{	printCurrentState();
		if (*filePointer != 0x0D)
		{
			//The string begins here.
			filePointer++;
			state = 4;
		}

		break;
		}
		case 4:
		{	printCurrentState();
		if (*filePointer != 0x0D)
		{
			state = 4;
			filePointer++;
		}

		else if (*filePointer == 0x0D)
		{
			//The string ended here.
			//TODO Retain the string i a variable.

			state = 5;
			filePointer++;

		}
		break;
		}
		case 5:

		{
			printCurrentState();
			if (*filePointer == 0x0A)
			{
				state = 6;
				filePointer++;
			}
			else
			{
				printError();
				return STATE_MACHINE_FINISHED_WITH_ERRORS;
			}

			break;
		}
		case 6:

		{
			printCurrentState();
			if (*filePointer == '+') {
				state = 3;
				filePointer++;

			}
			else if (*filePointer == 0x0D) {
				state = 7;
				filePointer++;
			}

			else
			{
				printError();
				return STATE_MACHINE_FINISHED_WITH_ERRORS;
			}
			break;
		}

		case 7:

		{
			printCurrentState();
			if (*filePointer == 0x0A) {
				state = 8;
				filePointer++;
			}

			else
			{
				printError();
				return STATE_MACHINE_FINISHED_WITH_ERRORS;
			}
			break;
		}

		case 8:

		{
			printCurrentState();
			if (*filePointer == 'O' || *filePointer == 'o') {
				state = 9;
				filePointer++;

			}
			else if (*filePointer == 'E' || *filePointer == 'e') {
				state = 13;
				filePointer++;
			}
			else
			{
				printError();
				return STATE_MACHINE_FINISHED_WITH_ERRORS;
			}
			break;
		}

		case 9:

		{
			printCurrentState();
			if (*filePointer == 'K' || *filePointer == 'k') {
				state = 10;
				filePointer++;

			}

			else
			{
				printError();
				return STATE_MACHINE_FINISHED_WITH_ERRORS;
			}
			break;
		}

		case 10:

		{
			printCurrentState();
			if (*filePointer == 0x0D) {
				state = 11;
				filePointer++;

			}

			else
			{
				printError();
				return STATE_MACHINE_FINISHED_WITH_ERRORS;
			}
			break;
		}

		case 11:

		{
			printCurrentState();
			if (*filePointer == 0x0A) {
				state = 12;
				filePointer++;

			}

			else
			{
				printError();
				return STATE_MACHINE_FINISHED_WITH_ERRORS;
			}
			break;
		}

		case 12:

		{	//final state
			printCurrentState();
			return STATE_MACHINE_FINISHED_SUCCESFULLY;

		}

		case 13:

		{
			printCurrentState();
			if (*filePointer == 'R' || *filePointer == 'r') {
				state = 14;
				filePointer++;

			}

			else
			{
				printError();
				return STATE_MACHINE_FINISHED_WITH_ERRORS;
			}
			break;
		}

		case 14:

		{
			printCurrentState();
			if (*filePointer == 'R' || *filePointer == 'r') {
				state = 15;
				filePointer++;

			}

			else
			{
				printError();
				return STATE_MACHINE_FINISHED_WITH_ERRORS;
			}
			break;
		}

		case 15:

		{
			printCurrentState();
			if (*filePointer == 'O' || *filePointer == 'o') {
				state = 16;
				filePointer++;

			}

			else
			{
				printError();
				return STATE_MACHINE_FINISHED_WITH_ERRORS;
			}
			break;
		}

		case 16:

		{
			printCurrentState();
			if (*filePointer == 'R' || *filePointer == 'r') {
				state = 16;
				filePointer++;

			}

			else
			{
				printError();
				return STATE_MACHINE_FINISHED_WITH_ERRORS;
			}
			break;
		}



		default: {printf("Default\n");
			return STATE_MACHINE_NOT_FINISHED;

		}

				 return STATE_MACHINE_NOT_FINISHED;
		}

		


	}
}
