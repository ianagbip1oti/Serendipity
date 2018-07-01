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
#include <cstring>
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
                while (true) {
                    std::string search;
                    char confirmation;
                    getStringInput("Enter the book you want to search. 'cancel' to go back", search);
                    if (search == "cancel") {
                        break;
                    }
                    int searchIndex = lookUpBook(search, bookTitle, isbn, index);

                    if (searchIndex == -1) {
                        std::cout << "That book was not found, press enter to search again." << std::endl;
                        std::cin.get();
                        continue;
                    }

                    std::cout << "[FOUND]: " << bookTitle[searchIndex] << "\nView this record? (y/n)\n";
                    std::cin.ignore(1000, '\n');
                    std::cin >> confirmation;
                    if (tolower(confirmation) == 'y'){
                        clearScreen();
                        printBook(bookTitle, isbn, author, publisher, dateAdded, quantity, wholesaleCost, retailPrice,
                                  searchIndex);
                        std::cin.ignore(1000, '\n');
                        std::cin.get();
                    }
                    break;
                }
                break;
            case 2:
                addBook(bookTitle, isbn, author, publisher, dateAdded, quantity, wholesaleCost, retailPrice, index);
                break;
            case 3:
                if (index == 0){
                   std::cout << "There are no books to edit, press enter to return to the menu." << std::endl;
                   std::cin.ignore(1000, '\n');
                   std::cin.get();
                   break;
                }
                editBook(bookTitle, isbn, author, publisher, dateAdded, quantity, wholesaleCost, retailPrice, index);
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
    struct tm *time_info;
    char buffer[60];
    time(&raw);
    time_info = localtime(&raw);
    strftime(buffer, sizeof(buffer), "%d-%m-%Y", time_info);

    while (true) {
        clearScreen();
        std::cout << "-------------------------------------------------------------------------------------------\n"
                  << "                                 Serendipity Booksellers                                   \n"
                  << "                                      Add Book                                             \n"
                  << "                              Today's date: " << buffer << "\n"
                  << "                            Current Database Size: " << index << "                       \n"
                  << "                                                                                           \n"
                  << "         1. Enter book title          | --Old Title           " << newBookTitle << "\n"
                  << "         2. Enter ISBN                | --Old ISBN            " << newISBN << "\n"
                  << "         3. Enter Author              | --Old Author          " << newAuthor << "\n"
                  << "         4. Enter Publisher           | --Old Publisher       " << newPublisher << "\n"
                  << "         5. Enter Date                | --Old Date Added      " << newDate << "\n"
                  << "         6. Enter Quantity            | --Old Quantity        " << newQuantity << "\n"
                  << "         7. Enter Wholesale Cost      | --Old Wholesale Cost  $" << newWholesaleCost << "\n"
                  << "         8. Enter Retail Price        | --Old Retail Price    $" << newRetailPrice << "\n"
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
                if (index >= 20) {
                    std::cout << "The database is already completely full." << std::endl;
                    break;
                }
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
              << "  Wholesale Cost: $" << wholesaleCost[index] << std::endl
              << "    Retail Price: $" << retailPrice[index] << std::endl
              << "Press Enter to go back" << std::endl;
}


int lookUpBook(string search, string bookTitle[20], string isbn[20], int &index) {
    for (int i = 0; i < index; i++) {
        const int titlePos = bookTitle[i].find(search);
        const bool matchingISBN = isbn[i] == search;

        if (titlePos > -1 || matchingISBN) {
            return i;
        }
    }
    return std::string::npos;
}

void editBook(string bookTitle[20], string isbn[20], string author[20], string publisher[20],
              string dateAdded[20], int quantity[20], double wholesaleCost[20], double retailPrice[20], int &index) {


    int choice;
    char date[60];
    getDate(date);

    while (true) {
        clearScreen();
        std::cout << "-------------------------------------------------------------------------------------------\n"
                  << "                                 Serendipity Booksellers                                   \n"
                  << "                                      Edit Book                                            \n"
                  << "                              Today's date: " << date << "\n"
                  << "                            Current Database Size: " << index << "                       \n"
                  << "                                                                                           \n"
                  << "         1. Enter book title                | --Title           " << bookTitle[index] << "\n"
                  << "         2. Enter ISBN                      | --ISBN            " << isbn[index] << "\n"
                  << "         3. Enter Author                    | --Author          " << author[index] << "\n"
                  << "         4. Enter Publisher                 | --Publisher       " << publisher[index] << "\n"
                  << "         5. Enter Date                      | --Date Added      " << dateAdded[index] << "\n"
                  << "         6. Enter Quantity                  | --Quantity        " << quantity[index] << "\n"
                  << "         7. Enter Wholesale Cost            | --Wholesale Cost  $" << wholesaleCost[index] << "\n"
                  << "         8. Enter Retail Price              | --Retail Price    $" << retailPrice[index] << "\n"
                  << "         0. Return to main menu                                                            \n"
                  << "                                                                                           \n"
                  << "-------------------------------------------------------------------------------------------\n";
        getIntegerInput("Enter a number between 0-9", choice);

        switch (choice) {
            case 1: {
                getStringInput("Please enter the book name", bookTitle[index]);
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
                    isbn[index] = temp;
                    break;
                }
                break;
            }
            case 3: {
                getStringInput("Please enter the author", author[index]);
                break;
            }
            case 4: {
                getStringInput("Please enter the publisher", publisher[index]);
                break;
            }
            case 5: {
                getStringInput("Please enter the date", dateAdded[index]);
                break;
            }
            case 6: {
                getIntegerInput("Please enter the quantity on hand", quantity[index]);
                break;
            }
            case 7: {
                getDoubleInput("Please enter the wholesale cost", wholesaleCost[index]);
                break;
                std::cin.clear();

            }
            case 8: {
                getDoubleInput("Please enter the retail price", retailPrice[index]);
                break;
            }
            case 0:
                return;
            default:
                std::cin.ignore(1000, '\n');
                std::cout << "That was not a valid choice... Press enter to return" << std::endl;
                std::cin.get();
                continue;
        }
    }
}

void deleteBook() {
    std::cout << "You selected Delete Book" << std::endl;
}

void getDate(char target[60]) {
    time_t raw;
    struct tm *time_info;
    char buffer[60];
    time(&raw);
    time_info = localtime(&raw);
    strftime(buffer, sizeof(buffer), "%d-%m-%Y", time_info);
    strcpy(target, buffer);
}
