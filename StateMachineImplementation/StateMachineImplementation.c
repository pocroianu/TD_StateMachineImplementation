#include"StateMachineImplementation.h"

StateMachineStructure stateMachineData;

static uint8_t lineCount = 0;
static uint8_t lineSize = 0;

//Used to print something if an error occurs.
void printError() {

	//printf("Error \n");
}

//Prints the current state.
void printCurrentState() {
	printf("CurrentState : %d - Character : %d \n", state, *filePointer);
}

//Prints the string that was memorized.
void printStateMachineData() {
	printf("State Machine Content : \n");

	int i;
	for (i = 0; i < lineCount; i++) {
		printf("%s", stateMachineData.content[i]);
		printf("\n");
	}
}


//The main function.
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
			if (lineSize < Max_String_Size) {
				stateMachineData.content[lineCount][lineSize] = *filePointer;
				lineSize++;
			}
			filePointer++;
			state = 3;
		}

		else if (*filePointer == 0x0D)
		{
			//The string ended here.
			stateMachineData.content[lineCount][lineSize] = '\0';
			//Reset the line size for the new line.
			lineSize = 0;
			if (lineCount < Max_String_Count)
				lineCount++;


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
