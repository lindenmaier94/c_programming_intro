#include <stdio.h>
#define NUM_OF_ELEMS 10

// This program demonstrates how 2-D (or arbitrary dimensional) arrays can be handled in C.
// Furthermore it introduces functions defined in the main.c file. As in Matlab,
// functions can be defined in separate C files and in main.c that is analogous to
// creating functions in Matlab script instead of in separate file.
// The best practice is to collect corresponding functions into a separate C file 
// that is shown in FunctionDemo.sln.


// Functions should be declared before their definition. Function declaration is a kind of
// blueprint of the function that describes the input and output interface of the function.
// Function declarations shall be located after preprocessor definitions before main function.
// FUNCTION DECLARATIONS HERE:
void fillArrayPointer(int *array2d, int numOfRows, int numOfColumns);
void printArrayPointer(int *array2d, int numOfRows, int numOfColumns);
void fillArray(int array2d[][NUM_OF_ELEMS], int numOfRows, int numOfColumns);
void printArray(int array2d[][NUM_OF_ELEMS], int numOfRows, int numOfColumns);



// Actually main is also a function that is called when the built .exe is run.
int main(int argc, char* argv[])
{
	printf("This program is intended to create a multiplication table.\n");

	// Creating a 2-D array to store the elements of multiplication table.
	// The array sizes shall be given by constants or either macros.
	// Here NUM_OF_ELEMS macro is used. (#define NUM_OF_ELEMS 10)
	int multiplicationTable[NUM_OF_ELEMS][NUM_OF_ELEMS];

	// Fill the elements of the multiplication table
	fillArrayPointer((int *)multiplicationTable, NUM_OF_ELEMS, NUM_OF_ELEMS);

	// Display the elements of the multiplication table
	printArrayPointer((int *)multiplicationTable, NUM_OF_ELEMS, NUM_OF_ELEMS);

	printf("------------------------------------------------------------------\n");
	printf("Array is passed to functions as array. Array indexing is used.\n\n");

	int multiplicationTable2[NUM_OF_ELEMS][NUM_OF_ELEMS];

	// Fill the elements of the multiplication table
	fillArray(multiplicationTable2, NUM_OF_ELEMS, NUM_OF_ELEMS);

	// Display the elements of the multiplication table
	printArray(multiplicationTable2, NUM_OF_ELEMS, NUM_OF_ELEMS);

	return 0;
}

// The function definitions are giben after main function, HERE:

void fillArrayPointer(int* array2d, int numOfRows, int numOfColumns)
{
	// This function takes the pointer of array2d (points to the 0th element of the array),
	// and the array elements are indexed with linear indexing.
	// Functions that work on array have a void return value (no return value) since the
	// elements of the array are reached directly at their memory adress. So, the elements
	// of the original array are overwritten!
	for (int i = 0; i < numOfRows; i++)
	{
		for (int j = 0; j < numOfColumns; j++)
		{
			// NOTE: array2d is pointer so getting the array elements' value needs dereferencing by * operator
			*((array2d + i * numOfRows) + j) = (i + 1) * (j + 1);
		}
	}
}

void printArrayPointer(int* array2d, int numOfRows, int numOfColumns)
{
	for (int i = 0; i < numOfRows; i++)
	{
		for (int j = 0; j < numOfColumns; j++)
		{
			printf("%3d  ", *((array2d + i * numOfRows) + j));
		}
		printf("\n");
	}
}

void fillArray(int array2d[][NUM_OF_ELEMS], int numOfRows, int numOfColumns)
{
	// This function demonstrates an alternate form to pass a 2-D array to a function.
	// In this case the array2d is interpreted as an array using brackets ([]).
	// However, the second dimension shall be difned exactly!
	for (int i = 0; i < numOfRows; i++)
	{
		for (int j = 0; j < numOfColumns; j++)
		{
			// In this case the array elements can be reached by array indexing.
			// Note that they are still pointers, so the values of the original array
			// are overwritten in this form too.
			array2d[i][j]= (i + 1) * (j + 1);
		}
	}
}

void printArray(int array2d[][NUM_OF_ELEMS], int numOfRows, int numOfColumns)
{
	for (int i = 0; i < numOfRows; i++)
	{
		for (int j = 0; j < numOfColumns; j++)
		{
			printf("%3d  ", array2d[i][j]);
		}
		printf("\n");
	}
}
