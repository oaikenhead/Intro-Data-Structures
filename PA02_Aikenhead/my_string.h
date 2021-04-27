/*
 * String Function Declarations
 */

#ifndef MY_STRING_H_
#define MY_STRING_H_

#include <iostream>

std::size_t myStringLength(const char * str);

int myStringCompare(const char * str1, const char * str2);

char * myStringCopy(char * destination, const char * source);

char * myStringCat(char * destination, const char * source);

#endif//MY_STRING_H_
