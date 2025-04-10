#include <stdio.h>
#include "scanfSecure.h"

void readNumbers(int numberArray[], int numOfNumbers, int min, int max)
{
	// This function reads the guesses of the user based on own scanfSecure function.
	int isScanned;
	for (int i = 0; i < numOfNumbers; i++)
	{
		printf("%d. guess: ", i + 1);
		isScanned = scanfSecure("%d", &numberArray[i]);
		while ((!isScanned) || (numberArray[i] < min || numberArray[i] > max))
		{
			if (!isScanned)
			{
				printf("The given input does not match the desired format (integer).\n");
			}
			else
			{
				printf("The given input is out of the desired range [%d, %d]\n", min, max);
			}
			printf("Please, try again!\n");
			printf("%d. guess: ", i + 1);
			isScanned = scanfSecure("%d", &numberArray[i]);
		}
		// Check if the guessed number has already been put in the array
		for (int iPrev = 0; iPrev < i; iPrev++)
		{
			if (numberArray[iPrev] == numberArray[i])
			{
				i--;
				printf("This number has already been guesses.\n");
				break;
			}
		}
	}
}