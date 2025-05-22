// Bultin function declarations
#include <stdio.h> // printf, scanf
#include <stdlib.h> // rand, srand
#include <time.h> // time(0)

// Own function declarations
#include "drawNumbers.h"
#include "readGuesses.h"
#include "printElements.h"
#include "sortElements.h"
#include "countRightGuesses.h"

// Global constants (macros)
#define MIN 1
#define MAX 90
#define NUM_OF_DRAWS 5
#define ASCEND 1
#define DESCEND -1

int main(int argc, char* argv[])
{
	/* This program is a lottery machine that requires NUM_OF_DRAWS number of guesses from the user
	* and then draws NUM_OF_DRAWS number of random integers between MIN and MAX. Finally, the program
	* counts the number of right guesses.
	*/
	printf("This program is a lottery game. Good luck!\n");
	printf("Please guess the numbers.\n");
	int guessArray[NUM_OF_DRAWS]; // array to store the user guesses
	readNumbers(guessArray, NUM_OF_DRAWS, MIN, MAX); // reading user guesses
	bubbleSort(guessArray, NUM_OF_DRAWS, ASCEND); // sorting the guessed numbers
	printf("------------------------------------------------------\n");
	printf("The sorted guessed numbers:\n");
	printElements(guessArray, NUM_OF_DRAWS, "%2d "); // printing sorted guesses
	

	srand(time(0)); // to get random numbers set the random seed to the processor time (time(0))
	int drawnArray[NUM_OF_DRAWS]; // array to store the drawn numbers
	generateRandomNumbers(drawnArray, NUM_OF_DRAWS, MIN, MAX); // draw the numbers
	bubbleSort(drawnArray, NUM_OF_DRAWS, ASCEND); // sorting the drawn numbers

	printf("------------------------------------------------------\n");
	printf("The sorted drawn numbers:\n");
	printElements(drawnArray, NUM_OF_DRAWS, "%2d "); // printing sorted drawn numbers

	int numOfRightGuesses = countRightGuesses(guessArray, drawnArray, NUM_OF_DRAWS); // count the right guesses
	printf("------------------------------------------------------\n");
	printf("The number of right guesses: %d\n", numOfRightGuesses);
}