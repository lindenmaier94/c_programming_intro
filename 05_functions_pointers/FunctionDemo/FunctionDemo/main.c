#include <stdio.h>
// If you try to include a header file with between <> the header file is searched
// in the compiler's standar libary implementation. Using "" notation searches the 
// header file in the project folder.

// Including own header files of user defined functions using "":
#include "arithmeticOperations.h"
#include "scanfSecure.h"
#include "printFunction.h"

// This project demonstrates how functions can be defined in separate C files.
// The program asks the user for two floating-point numbers and reads them with
// scanfSecure function defined in this project. Then, arithmetic operations are
// performed on the scanned variables that are defined in arithmeticOperations.c.

int main(int argc, char* argv[])
{
	double number1 = 0.0;
	double number2 = 0.0;

	printf("Please give two floating point numbers!\n");
	// Read user input with own scanfSecure function
	scanfBuffer("%lf", &number1, "x = ");
	scanfBuffer("%lf", &number2, "y = "); // Read user input with own scanfSecure function

	double sum = addNumbersd(number1, number2);
	double difference = subtractNumbersd(number1, number2);
	printFunction(number1, number2, '+', sum);
	printFunction(number1, number2, '-', difference);

	double originalNumber1 = number1;
	incrementd(&number1);	
	printFunction(originalNumber1, 1, '+', number1);
}