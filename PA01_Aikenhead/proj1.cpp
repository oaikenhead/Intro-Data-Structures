/**
 * Olliver Aikenhead
 * Project 01
 *
 * This project is compiled using g++ in the terminal of linux.
 * Sorts a list of names from an input file, and stores them into an output file.
 * 
 * Adding makefile
 */

#include <iostream>
#include <fstream>

using namespace std;

/* global variables */
const int NAMES = 10;// 10 is the original that works
const int SIZE = 45; // 45 works, 31,34,37,39,42 half works

/* function prototypes */
// string copy
void myStringCopy(char destination [], const char source []);

// string length
int myStringLength(const char str []);

// string compare
int myStringCompare(const char str1 [], const char str2 []);

// string swap
void myStringSwap(char str1[], char str2[]);

// read names
void readNames(char input_file [], char namesArray[NAMES][SIZE]);

// print names to terminal
void printNamesToTerminal(char namesArray[NAMES][SIZE]);

// alphabet sort
void sortNamesAlphabetic(char namesArray[NAMES][SIZE]);

// length sort
void sortNamesByLength(char namesArray[NAMES][SIZE]);

// print names to output file
void printNamesToFile(std::ofstream& output_file, char namesArray[NAMES][SIZE]);

/* main program execution */
int main(){
  char namesArray[NAMES][SIZE];
  char input_file[SIZE];
  char output_file[SIZE];

  // (1) asking user for input and output file names
  cout << "Please enter the input file name: ";
  cin >> input_file;

  cout << "Please enter the output file name: ";
  cin >> output_file;

  std::ofstream dest_file;
  dest_file.open(output_file);

  // (2)
  readNames(input_file, namesArray);

  // (3) print the unsorted list of names to the terminal
  cout << "\nUnsorted Data (Original Input Order and Name)\n"
       << "=============================" << endl;
  printNamesToTerminal(namesArray);

  // (4, 5, 8) sort list of names alphabetically, then print to terminal, then to file
  cout << "\nAlphabetcially Sorted Data (Original Input Order and Name)\n"
       << "===========================" << endl;
  sortNamesAlphabetic(namesArray);
  printNamesToTerminal(namesArray);
  printNamesToFile(dest_file, namesArray);

  // (6, 7, 8) sort list of names by length, print to terminal, then to file
  cout << "\nSorted-by-Length –and– Alphabetically Data (Original Input Order and Name)\n"
       << "===========================" << endl;
  sortNamesByLength(namesArray);
  printNamesToTerminal(namesArray);
  printNamesToFile(dest_file, namesArray);

  dest_file.close();

  return 0;  // terminate program
}

/* function definitions */
// string copy fcn def
void myStringCopy(char destination [], const char source []){
  int i=0;

  // counting while incrementing
  while(source[i] != '\0'){
    destination[i] = source[i];
    i++;
  }

  // placing null terminator at the end of the string
  destination[i] = '\0';
}

// string length fcn def
int myStringLength(const char str []){
  // this variable records the length of the string
  size_t len_count;

  // this loop is counting the length of the array
  for(len_count=0; str[len_count] != '\0'; len_count++);

  return len_count;
}

// string compare fcn def
int myStringCompare(const char str1 [], const char str2 []){
  int compare = max(myStringLength(str1), myStringLength(str2));

  for(int i=0; i<compare; i++){
    // str1 is larger
    if(str2[i] < str1[i]){
      return 1;
    }

    // str2 is larger
    if(str1[i] < str2[i]){
      return -1;
    }
  }

  return 0;
}

// string swap fcn def
void myStringSwap(char str1[], char str2[]){
  // temp array for swapping values into other elements of the array
  char temp_arr[SIZE];

  // moving the string contents one string at a time
  myStringCopy(temp_arr, str1);
  myStringCopy(str1, str2);
  myStringCopy(str2, temp_arr);
}

// read names fcn def
void readNames(char input_file [], char namesArray [NAMES][SIZE]){
  fstream FILE;

  FILE.open(input_file, fstream::in);

  if(FILE.is_open()){
    for(int i=0; i<NAMES && !FILE.eof(); i++){
      namesArray[i][0] = '0' + i;
      namesArray[i][1] = ' ';

      FILE.getline(&namesArray[i][2], SIZE); // originally (SIZE - 3)
    }

    FILE.close();
  }

}

// print names to terminal fcn def
void printNamesToTerminal(char namesArray[NAMES][SIZE]){

  // printing data to the terminal one line at a time
  for(int i=0; i<NAMES; i++){
    cout << namesArray[i] << endl;
  }
}

// alphabet sort fcn def
void sortNamesAlphabetic(char namesArray[NAMES][SIZE]){
  bool condition = false;

  do{
    condition = false;

    // moving through the array checking order
    for(int i=0; i<NAMES-1; i++){

      // using string compare to find alphabetic order
      if(myStringCompare(&namesArray[i][2], &namesArray[i+1][2]) > 0){
        // swapping the strings into order and changing condition to terminate loop
        myStringSwap(namesArray[i], namesArray[i+1]);
        condition = true;
      }
    }
  } while(condition);
}

// length sort
void sortNamesByLength(char namesArray[NAMES][SIZE]){
  bool condition = false;

  do{
    condition = false;

    // moving through array while keeping count
    for(int i=0; i<NAMES-1; i++){ // was NAMES-1

      // comparing length
      if(myStringLength(namesArray[i]) > myStringLength(namesArray[i+1])){

        // swapping strings according to length and changing condition to terminate loop
        myStringSwap(namesArray[i], namesArray[i+1]);
        condition = true;
      }
    }
  } while(condition);
}

// print names to output file NEEDS WORK
void printNamesToFile(std::ofstream& output_file, char namesArray[NAMES][SIZE]){
  // writing to the file one line at a time
  for(int i=0; i<NAMES; i++){
    output_file << ' ' << namesArray[i] << endl;
  }
}
