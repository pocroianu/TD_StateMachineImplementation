// StateMachineImplementation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include"StateMachineImplementation.h"


int main(int numberOfParameters, char* parameters[]) {
	//
	printf("State Machine Implementation \n");



	//If the number of parameters is bellow 2,the app will exit.
	if (numberOfParameters < 2)
	{
		printf("Too few parameters \n");
		exit(0);
	}


	//Reading from the in file.
	char inbuffer[Max_String_Size]; 
	int n;
	FILE *f;
	f = fopen("in.txt", "rb");
	n = fread(inbuffer, 1, Max_String_Size, f);
	inbuffer[n] = '\0';
	filePointer = inbuffer;


	//Print the file contents on the screen.
	printf("I managed to read the following text : \n");
	puts(inbuffer);
	printf("\n");


	//Start the finite state machine.
	uint8_t returnState;
	returnState = parse();


	//Check if the finite state machine ended succsesfully.
	if (returnState == STATE_MACHINE_FINISHED_SUCCESFULLY)
	{
		printf("\nState Machine finished succsesfully. \n");
		printStateMachineData();
	}
	else if (returnState == STATE_MACHINE_FINISHED_WITH_ERRORS) {
		printf("\nState Machine finished with errors. \n");
	}
	else if (returnState == STATE_MACHINE_NOT_FINISHED) {
		printf("\nState Machine did not finish succsesfully. \n");
	}


	return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
