/* * * * * * * * * * * * * * *
 * Olliver Aikenhead         *
 * Project 4                 *
 * Menu Header File          *
 * * * * * * * * * * * * * * */

#ifndef MENU_H_
#define MENU_H_

#include "Agency.h"

void userMenuPrompt();
void readIn(Agency agency);
void printAll(Agency agency);
void printFiltered(Agency agency);
void reserveOne(Agency agency);

#endif//MENU_H_
