#pragma once
#include <string>

/**
 * Preventing repetition
 */
using std::string;

/* **************************************************************
 * Pre-Condition: No post-conditions
 * Post-Condition: No post-conditions
 ***************************************************************/
void invMenu(string[20], string[20], string[20], string[20], string[20], int[20], double[20], double[20], int&);

/* **************************************************************
 * Pre-Condition: The book's isbn or title must be with in the array
 * Post-Condition: No post-conditions
 ***************************************************************/
int lookUpBook(string, string[20], string[20],  int&);

/* **************************************************************
 * Pre-Condition: No post-conditions
 * Post-Condition: No post-conditions
 ***************************************************************/
void addBook(string[20], string[20], string[20], string[20], string[20], int[20], double[20], double[20], int&);

/* **************************************************************
 * Pre-Condition: No post-conditions
 * Post-Condition: No post-conditions
 ***************************************************************/
void editBook(string[20], string[20], string[20], string[20], string[20], int[20], double[20], double[20], int&);

/* **************************************************************
 * Pre-Condition: No post-conditions
 * Post-Condition: No post-conditions
 ***************************************************************/
void deleteBook(string[20], string[20], string[20], string[20], string[20], int[20], double[20], double[20], int, int&);

/* **************************************************************
 * Pre-Condition: No post-conditions
 * Post-Condition: No post-conditions
 ***************************************************************/
void printBook(string[20], string[20], string[20], string[20], string[20], int[20], double[20], double[20], int&);

/* **************************************************************
 * Pre-Condition: No post-conditions
 * Post-Condition: No post-conditions
 ***************************************************************/
void getDate(char[60]);
