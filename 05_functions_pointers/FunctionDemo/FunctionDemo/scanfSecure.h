#pragma once

// Function declarations in header file
int clearBuffer();
int scanfBuffer(const char* format, void* memoryAdress, const char* message);

// This does the same as pragma one. Both grant that the header is
// loaded once; therefore functions are not declared multiple times.
// 
//#ifndef _SCANF_SECURE_H
//int clearBuffer(void);
//int scanfSecure(const char* format, void* memoryAdress);
//#define _SCANF_SECURE_H
//#endif // !_SCANF_SECURE_H


