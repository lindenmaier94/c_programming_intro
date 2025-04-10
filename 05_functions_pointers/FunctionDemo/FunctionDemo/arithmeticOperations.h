#pragma once

double addNumbersd(double number1, double number2);
double subtractNumbersd(double number1, double number2);
double incrementd_BAD(double number);
void incrementd(double* number);

// This does the same as pragma one. Both grant that the header is
// loaded once; therefore functions are not declared multiple times.
// 
//#ifndef _OPERATIONS_H
//double addNumbersd(double number1, double number2);
//double subtractNumbersd(double number1, double number2);
//double incrementd_BAD(double number);
//void incrementd(double* number);
//#define _OPERATIONS_H
//#endif // !_OPERATIONS_H


