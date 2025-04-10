#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> // printf, scanf
#include <stdlib.h> // RAND_MAX, srand, rand
#include <time.h> // time()
#include <math.h> // sqrt()

// If you want to create a static array (fixed size) in C, you cannot initialize the size of the array by a variable since its value can be changed.
// Therefore, we usually define the maximum size of the array with a macro that will be constant and its value cannot be changed:
#define MAX_ARRAY_SIZE 1000 // defining a macro for the maximum size of the array

#define MIN -100 // macro definition for the minimum random value
#define MAX +100 // macro definition for the maximum random value
int main(int argc, char* argv[])
{
	printf("This program computes some statistics metrics of random numbers.\n");
	printf("----------------------------------------------------------------\n");

	// Scanning the input number cardinality
	printf("Please, give the number of inputs of what you would like to you work with!\n");
	printf("n = ");
	int numOfElements = 0;
	// We ask the user how many random numbers they want to generate. In this way, we are not forced to 
	// fill up the complete array with MAX_ARRAY_SIZE random elements.
	scanf("%d", &numOfElements);

	double numberArray[MAX_ARRAY_SIZE]; // Static array with fixed size (variable cannot be used to determine the size of the array)
	// We make sure that the number of random elements are not greater than MAX_ARRAY_SIZE not to exceed the maximum number of elements:
	numOfElements = (numOfElements > MAX_ARRAY_SIZE) ? MAX_ARRAY_SIZE : numOfElements; //max(numOfElements, MAX_ARRAY_SIZE)

	// Generating random numbers
	srand(time(0)); // Set the seed of the random number generator to the current system (processor) time ---> real random
	// In contrast to Matlab, in C programming the rand() function returns random integer values between 0 and a given RAND_MAX.
	// If you want to create a uniform floating point random between a given MIN and MAX value, the first step is to create a 
	// normalized floating-point random between 0 and 1. This can be achieved by dividing the random number given by rand() with
	// RAND_MAX. You have to take care of the floating-point divison, so the RAND_MAX and rand() should be converted to
	// floating-point number (double or float) before the divison. Then, the normalized random between 0 and 1 can be rescaled to
	// 0 and (MAX - MIN) by multiplying it with (MAX - MIN). Finally, this random is offseted by MIN value to grant the generated
	// random number is between MIN and MAX.
	printf("------------------------------------------------------------------\n");
	printf("The maximum value given by rand() function: %d\n", RAND_MAX); 


	printf("------------------------------------------------------------------\n");
	printf("The randomly generated numbers: \n");
	for (int i = 0; i < numOfElements; i++)
	{
		numberArray[i] = MIN + (MAX - MIN) * ((double)rand() / (double)RAND_MAX);
		printf("%+9.4lf\n", numberArray[i]);
	}

	// Compute statistics: average, deviation, min, max

	printf("------------------------------------------------------------------\n");
	printf("The statistics of the random numbers:\n");
	// Average
	double average = 0.0;
	for (int i = 0; i < numOfElements; i++)
	{
		average += numberArray[i];
	}
	average /= numOfElements;
	printf("average = %+9.4lf\n", average);

	// Standard deviation
	double standarDeviation = 0.0;
	for (int i = 0; i < numOfElements; i++)
	{
		standarDeviation += (average - numberArray[i]) * (average - numberArray[i]);
	}
	standarDeviation /= numOfElements;
	standarDeviation = sqrt(standarDeviation);
	printf("deviation = %+9.4lf\n", standarDeviation);

	// Min and max
	double minValue = MAX;
	double maxValue = MIN;
	for (int i = 0; i < numOfElements; i++)
	{
		if (numberArray[i] < minValue)
		{
			minValue = numberArray[i];
		}

		if (numberArray[i] > maxValue)
		{
			maxValue = numberArray[i];
		}
	}
	printf("min value = %+9.4lf\n", minValue);
	printf("max value = %+9.4lf\n", maxValue);

	return 0;
}