#include <stdio.h>

int scanfSecure(const char* format, void* memoryAdress)
{
	// This function scans arbitrary type of variables extended with buffer handling.
	// It takes two inputs: the format in what we would like to scan the user input 
	// (e.g., "%lf" in case of floating-point numbers) and the memory adress of the
	// variable in what the user input shall be read. The format has const char* type
	// that means it is a constant pointer that points to a character. Actually this 
	// type describes a constant character array (string). The memory adress is type 
	// of void* meaning that is pointer storing the memory adress of variable with 
	// arbitrary type.

	// The scanfSecure always waits for a user input until the user input is succesfully scaned 
	// according to the given format. First the buffer is handled by clearing it if it is not empty

	// Delete the buffer content before calling scanf() to make sure that user input will be requested.
	clearBuffer();

	// Secondly, it tries to scan the given user input according to the given format. If the scan
	// was not succesful it gives a hint for the user.
	int isScanned = scanf(format, memoryAdress);

	// Delete the buffer content after scanf() and check is the input was partially scanned and something
	// remained in the buffer (e.g., the user gives a 1.15 floating-point number: in this case the integer 
	// part 1 is scanned by the scanf, but '.15' remains in the buffer.Therefore, the user input
	// does not match the given format.)

	int numOfBufferedChar = clearBuffer();

	// The scanf is assumed to be succesful if there is at least one scanned variable
	// and there are no buffered characters that could not be parsed according to the given format.
	int isScanSuccesful = isScanned && (numOfBufferedChar == 0);
	return isScanSuccesful;
}


int clearBuffer()
{
	// The standard input buffer (stdin) stream where the user inputs are stored
	// has FILE* type which is pointer that points to the input buffer.
	// The input buffer is actually a struct with field _Placeholder that points 
	// to the memory adress of the buffered characters. The arrow operator (->)
	// selects a specific field of the struct to what the pointer points.
	// Example: pointerOfTheStruct->fieldname
	FILE* bufferStream = stdin;
	// NOTE that the buffer contains a character array (string) actually the
	// buffered characters; therefore it is pointer.
	char* bufferPointer = bufferStream->_Placeholder;


	int numOfBufferedChar = 0;
	char character;

	// Until the input buffer is not used (not initialized), the bufferPointer is 
	// null pointer (NULL) that means it points to nothing. If we try to delete the
	// content of the unitialized buffer using getchar() function it will wait for
	// user input just as we use scanf(). Therefore, first we check whether the
	// bufferPointer has already been initialized. Similarly, if the content is only
	// a new line character the it will wait for user input, so we check that one as well.

	if ((bufferPointer != NULL) && (*bufferPointer != '\n'))
	{
		// If the buffer is initialized we can try to delete the content using getchar():

		// The getchar() functions reads a character from the buffer and then the character
		// is cleared from the buffer. If we call getchar() until we reach the end of the 
		// buffer (EOF) or a new line character (\n), the buffer will be empty. Therefore
		// using scanf will not neglect the user input, but it waits until the user fills
		// the buffer with his/her input.
		while (((character = getchar()) != EOF) && (character != '\n'))
		{
			numOfBufferedChar++;
		}
	}
	else
	{
		// If the buffer is not initialized yet or the bufferPointer points to a new line character, 
		// there is no buffered content.
		numOfBufferedChar = 0;
	}

	return numOfBufferedChar;
}