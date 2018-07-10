#pragma once

#include "bookinfo.h"

using std::string;
/* **************************************************************
 * pre-condition: no post-conditions
 * post-condition: no post-conditions
 ***************************************************************/
void displayMainMenu(Book[20], int&);

/* **************************************************************
 * pre-condition: no post-conditions
 * post-condition: no post-conditions
 ***************************************************************/
void clearScreen();

/* **************************************************************
 * pre-condition: no post-conditions
 * post-condition: no post-conditions
 ***************************************************************/
int getIntegerInput(const char*);

/* **************************************************************
 * pre-condition: no post-conditions
 * post-condition: no post-conditions
 ***************************************************************/
std::string getStringInput(const char*);

/* **************************************************************
 * pre-condition: no post-conditions
 * post-condition: no post-conditions
 ***************************************************************/
double getDoubleInput(const char*);

/* **************************************************************
 * pre-condition: no post-conditions
 * post-condition: no post-conditions
 ***************************************************************/
bool getBooleanInput(const char *);
