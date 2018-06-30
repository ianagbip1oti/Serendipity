/* ***********************************************************
 * Project Name:               Serendipity
 * File Name:                  invmenu.cpp
 * ***********************************************************
 * Creator's name and email:   Ali Bingol (abingol0@ivc.edu)
 * Course-Section:             CS1B
 * Creation Date:              6/19/2018
 * Date of Last Modification:  6/19/2018
 * ***********************************************************
 * Purpose: Displaying the main file for 
 * ***********************************************************
 * Algorithm:
 *  Step 1: Display the inventory memu for the user
 *  Step 2: Get their choice for the menu
 *  Step 3: Process their input
 * ***********************************************************
 *                      DATA DICTIONARY
 * 
 * CONSTANTS:
 * 
 * NAME                 DATA TYPE               VALUE
 * -------------        ------------            -----------
 * 
 * VARIABLES:
 * 
 * NAME                 DATA TYPE               VALUE
 * -------------        ------------            -----------
 * choice               int                     null
 * success              bool                    ?
 */
#include <iostream>
#include <iomanip>
#include "mainmenu.h"
#include "invmenu.h"

void invMenu(string bookTitle[20], string isbn[20], string author[20], string publisher[20],
             string dateAdded[20], int quantity[20], double wholesaleCost[20], double retailPrice[20], int &index) {

    int choice;
    while (true) {
        clearScreen();
        std::cout << "--------------------------------------------\n"
                  << "|         Serendipity Booksellers          |\n"
                  << "|            Inventory Database            |\n"
                  << "|                                          |\n"
                  << "|         1. Look up a book                |\n"
                  << "|         2. Add a book                    |\n"
                  << "|         3. Edit a book's record          |\n"
                  << "|         4. Delete a book                 |\n"
                  << "|         5. Return to the Main Menu       |\n"
                  << "|                                          |\n"
                  << "--------------------------------------------" << std::endl;
        getIntegerInput("Enter a number between 1-5", choice);
        switch (choice) {
            case 1:
                std::string search;
                getStringInput("Enter the book you want to search...", search);
                int searchIndex = lookUpBook(search, bookTitle, isbn, index);
                if (searchIndex == -1) {

                }
                break;
            case 2:
                addBook(bookTitle, isbn, author, publisher, dateAdded, quantity, wholesaleCost, retailPrice, index);
                break;
            case 3:
                editBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                return;
            default:
                std::cout << "That is not a valid choice" << std::endl;
                std::cin.ignore().get();
                continue;

        }

    }
}


void addBook(string bookTitle[20], string isbn[20], string author[20], string publisher[20],
             string dateAdded[20], int quantity[20], double wholesaleCost[20], double retailPrice[20], int &index) {

    string newBookTitle = "EMPTY";
    string newISBN = "EMPTY";
    string newAuthor = "EMPTY";
    string newPublisher = "EMPTY";
    string newDate = "EMPTY";
    int newQuantity = 0;
    double newWholesaleCost = 0;
    double newRetailPrice = 0;
    int choice;

    time_t raw;
    struct tm *timeinfo;
    char buffer[60];
    time(&raw);
    timeinfo = localtime(&raw);
    strftime(buffer, sizeof(buffer), "%d-%m-%Y", timeinfo);

    while (true) {
        clearScreen();
        std::cout << "-------------------------------------------------------------------------------------------\n"
                  << "                                 Serendipity Booksellers                                   \n"
                  << "                                      Add Book                                             \n"
                  << "                              Today's date: " << buffer << "\n"
                  << "                                                                                           \n"
                  << "         1. Enter book title                | --Title           " << newBookTitle << "\n"
                  << "         2. Enter ISBN                      | --ISBN            " << newISBN << "\n"
                  << "         3. Enter Author                    | --Author          " << newAuthor << "\n"
                  << "         4. Enter Publisher                 | --Publisher       " << newPublisher << "\n"
                  << "         5. Enter Date                      | --Date Added      " << newDate << "\n"
                  << "         6. Enter Quantity                  | --Quantity        " << newQuantity << "\n"
                  << "         7. Enter Wholesale Cost            | --Wholesale Cost  $" << newWholesaleCost << "\n"
                  << "         8. Enter Retail Price              | --Retail Price    $" << newRetailPrice << "\n"
                  << "         9. Save book to inventory                                                         \n"
                  << "         0. Return to main menu                                                            \n"
                  << "                                                                                           \n"
                  << "-------------------------------------------------------------------------------------------\n";
        getIntegerInput("Enter a number between 0-9", choice);

        switch (choice) {
            case 1: {
                getStringInput("Please enter the book name", newBookTitle);
                break;
            }
            case 2: {
                while (true) {
                    std::string temp;
                    getStringInput("Please enter the ISBN", temp);
                    int searchIndex = lookUpBook(temp, bookTitle, isbn, index);
                    if (searchIndex > -1) {
                        std::cout << "That ISBN already exists in the database." << std::endl;
                        continue;
                    }
                    newISBN = temp;
                    break;
                }
                break;
            }
            case 3: {
                getStringInput("Please enter the author", newAuthor);
                break;
            }
            case 4: {
                getStringInput("Please enter the publisher", newPublisher);
                break;
            }
            case 5: {
                getStringInput("Please enter the date", newDate);
                break;
            }
            case 6: {
                getIntegerInput("Please enter the quantity on hand", newQuantity);
                break;
            }
            case 7: {
                getDoubleInput("Please enter the wholesale cost", newWholesaleCost);
                break;
            }
            case 8: {
                getDoubleInput("Please enter the retail price", newRetailPrice);
                break;
            }
            case 9: {
                bookTitle[index] = newBookTitle;
                isbn[index] = newISBN;
                author[index] = newAuthor;
                publisher[index] = newPublisher;
                dateAdded[index] = newDate;
                quantity[index] = newQuantity;
                wholesaleCost[index] = newWholesaleCost;
                retailPrice[index] = newRetailPrice;
                index++;
                newBookTitle = "EMPTY";
                newISBN = "EMPTY";
                newAuthor = "EMPTY";
                newPublisher = "EMPTY";
                newDate = "EMPTY";
                newQuantity = 0;
                newWholesaleCost = 0;
                newRetailPrice = 0;
                break;
            }
            case 0:
                return;
            default:
                std::cin.clear();
                std::cin.ignore(1000, '\n');
                std::cout << "That was not a valid choice... Press enter to return" << std::endl;
                std::cin.get();
                continue;
        }
    }
}

void printBook(string bookTitle[20], string isbn[20], string author[20], string publisher[20],
             string dateAdded[20], int quantity[20], double wholesaleCost[20], double retailPrice[20], int &index) {
    std::cout << "           Title: " << bookTitle[index] << std::endl
              << "            ISBN: " << isbn[index] << std::endl
              << "          Author: " << author[index] << std::endl
              << "       Publisher: " << publisher[index] << std::endl
              << "      Date Added: " << dateAdded[index] << std::endl
              << "Quantity on hand: " << quantity[index] << std::endl
              << "  Wholesale Cost: " << wholesaleCost[index] << std::endl
              << "    Retail Price: " << retailPrice[index] << std::end;
}


int lookUpBook(string search, string bookTitle[20], string isbn[20], int &index) {
    for (int i = 0; i < index; i++) {
        const int titlePos = bookTitle[i].find(search);
        const bool matchingISBN = isbn[i] == search;

        if (titlePos > -1) {
            return titlePos;
        }
        else if (matchingISBN) {
            return matchingISBN;
        }
    }
    return -1;
}

void editBook() {
    std::cout << "You selected Edit Book" << std::endl;
}

void deleteBook() {
    std::cout << "You selected Delete Book" << std::endl;
}
