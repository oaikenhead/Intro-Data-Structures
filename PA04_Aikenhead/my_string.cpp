// string source file

#include "my_string.h"

size_t myStringLength(const char * str){
  int length;

  for(length=0; str[length] != '\0'; length++)
    continue;

  return length;
}

int myStringCompare(const char * str1, const char * str2){
  while(*str1 != '\0' && *str2 != '\0' && *str1 == *str2){
    str1++;
    str2++;
  }

  if(*str1 == *str2){
    return 0;
  }

  else if(*str1 > *str2){
    return 1;
  }

  else if(*str1 < *str2){
    return -1;
  }

  return 0;
}

char * myStringCopy(char * destination, const char * source){
  while(*source != '\0'){
    *destination = *source;
    destination++;
    source++;
  }

  *destination = '\0';

  return destination;
}

char * myStringCat(char * destination, const char * source){
  char *point = destination;
  while(*point){
    point++;
  }

  while(*point++ == *source++){
    ;
  }

  return destination;
}
