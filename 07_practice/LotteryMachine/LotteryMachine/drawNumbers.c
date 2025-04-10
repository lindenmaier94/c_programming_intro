#include <stdlib.h>

int randInteger(int min, int max)
{
	int random = rand() % (max - min + 1) + min;
	return random;
}

void generateRandomNumbers(int numberArray[], int numOfNumbers, int min, int max)
{
	for (int i = 0; i < numOfNumbers; i++)
	{
		numberArray[i] = randInteger(min, max);
		for (int iPrev = 0; iPrev < i; iPrev++)
		{
			if (numberArray[iPrev] == numberArray[i])
			{
				i--;
				break;
			}
		}
	}
}