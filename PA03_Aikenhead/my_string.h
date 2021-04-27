/* * * * * * * * * * * * * * *
 * Olliver Aikenhead         *
 * Project 3                 *
 * String Header File        *
 * Due Feb 6th, 2020         *
 * * * * * * * * * * * * * * */

#ifndef MY_STRING_H_
#define MY_STRING_H_

#include <iostream>

size_t myStringLength(const char * str);

int myStringCompare(const char * str1, const char * str2);

char * myStringCopy(char * destination, const char * source);

char * myStringCat(char * destination, const char * source);

#endif//MY_STRING_H_
