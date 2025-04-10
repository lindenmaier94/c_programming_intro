#include <stdio.h>

int scanfSecure(const char* format, void* memoryAdress)
{
	fseek(stdin, 0, SEEK_END); // Clearing buffer content in a straightforward manner
	int isScanned = 0;
	isScanned = scanf(format, memoryAdress);

	/* Checking if not the whole user input was able to pared and clear the buffer again.
	* (e.g., the user gives a 1.15 floating-point number: in this case the integer part 1
	* is scanned by the scanf, but '.15' remains in the buffer. Therefore, the user input
	* does not match the given format.)
	*/
	char character = 'a';
	int isBufferedInput = 0;
	while (((character = getchar()) != EOF) && (character != '\n')) 
	{
		isBufferedInput = 1;
	}

	// The scanf is assumed to be succesful if there is at least one scanned variable
	// and there are no buffered characters that could not be parsed according to the given format.
	int isScanSuccesful = (isScanned > 0) && (isBufferedInput == 0);
	return isScanSuccesful;
}