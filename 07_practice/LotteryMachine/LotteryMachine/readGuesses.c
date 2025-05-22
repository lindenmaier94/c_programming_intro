#include <stdio.h>
#include "scanfSecure.h"

void readNumbers(int numberArray[], int numOfNumbers, int min, int max)
{
	// This function reads the guesses of the user based on own scanfSecure function.
	int isScanOk = 0; // variable indicating if the scan was succesful and the user input matches the desired format
	int isRepeated = 0; // variable indicating if the current number has already been guessed
	int isGuessOk = 0; // variable indicating the current guess was completely okay
	for (int i = 0; i < numOfNumbers; i++)
	{
		
		do
		{
			printf("%d. guess: ", i + 1);
			isScanOk = scanfSecure("%d", &numberArray[i]);

			if (!isScanOk)
			{
				printf("The given input does not match the desired (integer) format.\n");
			}
			else if (numberArray[i] < min || numberArray[i] > max)
			{
				printf("The given input is out of the desired range [%d, %d]\n", min, max);
			}
			else
			{
				isRepeated = 0;
				// Check if the guessed number has already been put in the array
				for (int iPrev = 0; iPrev < i; iPrev++)
				{
					if (numberArray[iPrev] == numberArray[i])
					{
						isRepeated = 1;
						printf("This number has already been used.\n");
						break;
					}
				}
			}

			isGuessOk = isScanOk && (numberArray[i] >= min) && (numberArray[i] <= max) && !isRepeated;
			if (!isGuessOk)
			{
				printf("Please, try again!\n");
			}
		} while (!isGuessOk);
	}
}