#include <stdio.h>

void printElements(void* array[], int numOfElems, const char* format)
{
	// This function prints the elements of an arbitrary array in the given format (e.g., "%d")
	for (int i = 0; i < numOfElems; i++)
	{
		printf(format, array[i]);
	}
	printf("\n");
}