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
void invMenu(Book[20], int&);

/* **************************************************************
 * Pre-Condition: The book's isbn or title must be with in the array
 * Post-Condition: No post-conditions
 ***************************************************************/
int lookUpBook(string, Book [20], int&);

/* **************************************************************
 * Post-Condition: No post-conditions
 ***************************************************************/
void addBook(Book[20], int&);

/* **************************************************************
 * Pre-Condition: Book being edited exists
 * Post-Condition: No post-conditions
 ***************************************************************/
void editBook(Book[20], int&);

/* **************************************************************
 * Pre-Condition: book being edited exists
 * Post-Condition: No post-conditions
 ***************************************************************/
void deleteBook(Book[20], int, int);

/* **************************************************************
 * Pre-Condition: No post-conditions
 * Post-Condition: No post-conditions
 ***************************************************************/
void getDate(char[60]);
