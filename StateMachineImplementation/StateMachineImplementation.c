#include"StateMachineImplementation.h"

State_Machine_Return_Type returnError() {

	printf("Error \n");
	return STATE_MACHINE_FINISHED_WITH_ERRORS;
}

void printCurrentState() {
	printf("CurrentState : %d - Character : %c \n", state,*filePointer);
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
				returnError();
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

				returnError();
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
				returnError();
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
				returnError();
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
				returnError();
			}
			break;
		}

		case 7:

		{
			printCurrentState();
			if (*filePointer == 0x0A) {
				state = 8;

			}

			else
			{
				returnError();
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
				returnError();
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
				returnError();
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
				returnError();
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
				returnError();
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
				returnError();
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
				returnError();
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
				returnError();
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
				returnError();
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
