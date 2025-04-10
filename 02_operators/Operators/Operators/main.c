#include <stdio.h>

int main(int argc, char* argv[])
{
	// Division with integer numbers
	int integerNum1 = 10;
	int integerNum2 = 3;
	int integerQuotient = integerNum1 / integerNum2;
	printf("%d / %d = %d\n", integerNum1, integerNum2, integerQuotient);

	// Division with floating point numbers
	double floatNum1 = 10.0;
	double floatNum2 = 3.0;
	double floatQuotient = floatNum1 / floatNum2;
	printf("%g / %g = %g\n", floatNum1, floatNum2, floatQuotient);
	printf("%lf / %lf = %lf\n", floatNum1, floatNum2, floatQuotient);

	// The remainder of a division
	int remainder = integerNum1 % integerNum2;
	printf("%d %% %d = %d\n", integerNum1, integerNum2, remainder);

	printf("------------------------------------------------------\n");

	// Logical operators
	// Logical AND operation
	int condition1 = 1;
	if ((condition1) && (remainder == 10))
	{
		printf("Both conditions are satisfied.\n");
	}
	else
	{
		printf("One of the conditions or neither of them are satisfied.\n");
	}

	// Logical OR operation
	if ((condition1) || (remainder == 10))
	{
		printf("At least one of the conditions are satisfied.\n");
	}
	else
	{
		printf("None of the conditions is satisfied.\n");
	}

	printf("------------------------------------------------------\n");

	// Implicit type conversion: automatically done by the compiler 
	// mainly in order to prevent data loss. (from type with smaller memory --> bigger memory)
	// Let's look at the case of the previous division: 10 / 3!
	// However, now we will divide the integer 10 by the floating-point 3:
	printf("%d / %g = %g\n", integerNum1, floatNum2, integerNum1 / floatNum2);
	// The result is correctly a floating-point number because integerNum1 was
	// implicitly casted to float to prevent dataloss.

	// Explicit type conversion: manually done by the programmer, 
	// explicitly telling to the compiler to which datatype the variable should be converted.
	// This is called the casting:
	int castedQuotient = (int)floatQuotient;
	printf("(int)%g = %d\n", floatQuotient, castedQuotient);

	printf("------------------------------------------------------\n");

	// Pre- and postfix incerement/decrement
	integerNum1 = 0;
	integerNum2 = 10;
	integerNum1 = integerNum2++; // First the value of integerNum2 is used and after it is incremented
	printf("integerNum1 = %d integerNum2 = %d\n", integerNum1, integerNum2);

	integerNum1 = 0;
	integerNum2 = 10;
	integerNum1 = ++integerNum2; // First the value of integerNum2 is incremented and then the value is assigned to integerNum1
	printf("integerNum1 = %d integerNum2 = %d\n", integerNum1, integerNum2);

	printf("------------------------------------------------------\n");

	//Bit-wise logics

	// 1 0 1 0 1 0 1 0   &
	// 0 0 1 1 1 1 0 0
	// ---------------
	// 0 0 1 0 1 0 0 0 (40)

	unsigned char byte1 = 0b10101010; // (170)
	unsigned char byte2 = 0b00111100; // (60)

	printf("%d & %d = %d \n", byte1, byte2, byte1 & byte2);

	// 1 0 1 0 1 0 1 0   |
	// 0 0 1 1 1 1 0 0
	// ---------------
	// 1 0 1 1 1 1 1 0 (190)

	printf("%d | %d = %d \n", byte1, byte2, byte1 | byte2);

	//Bit-wise XOR
	// Note that in C programming ^ operator does not correspond to power but bit-wise XOR
	printf("Bit-wise XOR(%d, %d) = %d \n", byte1, byte2, byte1 ^ byte2);
	// Therefore, we have to pay attention using ^: 2^10 != 1024:
	printf("Bit-wise XOR(2,10) = %d \n", 2 ^ 10);

	//Bit shift
	// 0 0 1 1 1 1 0 0 --> 1 1 1 1 0 0 0 0 (240=60*2*2)
	printf("60 << 2 = %d\n", byte2 << 2);

	// 0 0 1 1 1 1 0 0 ---> 0 0 0 1 1 1 1 0
	printf("60 >> 1 = %d\n", byte2 >> 1);

	printf("------------------------------------------------------\n");

	//Conditional assignment
	int integerValue1 = 3;
	int integerValue2 = 19;
	int maxValue = (integerValue1 > integerValue2) ? integerValue1 : integerValue2;
	printf("max(%d, %d) = %d\n", integerValue1, integerValue2, maxValue);
}