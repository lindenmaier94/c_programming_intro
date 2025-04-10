#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>       /* fabs */
#include <stdlib.h>     /* strtod */

#define RELATIVE_TOLERANCE 1e-9
// #define ABS(x) (((x) > 0) ? (x) : (-(x)))
int main(int argc, char* argv[])
{
	printf("This program computes numerically the square root of a given number.\n");
	printf("--------------------------------------------------------------------\n");
	
	printf("Please, enter the number! x = ");
	double originalNumber = 0.0;

	// Handling command line input arguments
	if (argc < 2) // if the code is not called with extra command line arguments we read input from the used
	{
		printf("Please, enter the number!\n");
		printf("x = ");
		scanf("%lf", &originalNumber);
	}
	else // if there is an extra command line argument, the input is coming from there
	{
		originalNumber = strtod(argv[1], NULL); // convert string to double (command line argument is always a string)
	}

	// Handling of negative numbers
	double number = fabs(originalNumber);


	double lowerLimit = 0.0;
	double upperLimit = 0.0;
	double numericSqrt = 0.0;
	double numericSquare = 0.0;

	if (number > 1)
	{
		lowerLimit = 1;
		upperLimit = number;
	}
	else
	{
		lowerLimit = number;
		upperLimit = 1;
	}

	double tolerance = RELATIVE_TOLERANCE * number;
	while (fabs(numericSquare - number) > tolerance)
	{
		numericSqrt = (lowerLimit + upperLimit) / 2;
		numericSquare = numericSqrt * numericSqrt;
		if (numericSquare < number)
		{
			lowerLimit = numericSqrt;
		}
		else
		{
			upperLimit = numericSqrt;
		}
	}

	if (originalNumber < 0)
	{
		printf("The numeric COMPLEX solution of sqrt(x) = %gi", numericSqrt);
		return 1; // Return code for complex solution (kind of error code, but this error is handled)
	}
	else
	{
		printf("The numeric REAL solution of sqrt(x) = %g", numericSqrt);
		return 0; // Return code for real solution (error code for no error)
	}
	// If you run your code in Visual Studio IDE, the exit code is written to the console output and the output window at the bottom of IDE.
	// If you run the built .exe with cmd.exe or Windows Powershell the exit code can also be requested after running the program (PowerShell: $LASTEXITCODE, Cmd: %ERRORLEVEL%)
}