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
 * newBookTitle         string                  EMPTY
 * newISBN              string                  EMPTY
 * newAuthor            string                  EMPTY
 * newPublisher         string                  EMPTY
 * newDate              string                  EMPTY
 * newQuantity          int                     0
 * newWholesaleCost     double                  0
 * newRetailPrice       double                  0
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <bookinfo.h>
#include "mainmenu.h"
#include "invmenu.h"

void invMenu(Book books[20], int &index) {
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
        choice =getIntegerInput("Enter a number between 1-5");
        switch (choice) {
            case 1:
                while (true) {
                    std::string search;
                    char confirmation;
                    search = getStringInput("Enter the book you want to search. 'cancel' to go back");
                    if (search == "cancel") {
                        break;
                    }
                    int searchIndex = lookUpBook(search, books, index);

                    if (searchIndex == -1) {
                        std::cout << "That book was not found, press enter to search again." << std::endl;
                        std::cin.get();
                        continue;
                    }

                    std::cout << "[FOUND]: " << books[searchIndex].getTitle() << "\nView this record? (y/n)\n";
                    std::cin >> confirmation;
                    if (tolower(confirmation) == 'y') {
                        clearScreen();
                        books[searchIndex].print();
                        std::cin.ignore(1000, '\n');
                        std::cin.get();
                    }
                    break;
                }
                break;
            case 2:
                addBook(books, index);
                break;
            case 3: {
                if (index == 0) {
                    std::cout << "There are no books to edit, press enter to return to the menu." << std::endl;
                    std::cin.ignore(1000, '\n');
                    std::cin.get();
                    break;
                }
                std::string search;
                std::string confirmation;
                search = getStringInput("Enter the book you want to edit. 'cancel' to go back");
                if (search == "cancel") {
                    break;
                }
                int searchIndex = lookUpBook(search, books, index);


                if (searchIndex == -1) {
                    std::cout << "That book was not found, press enter to search again." << std::endl;
                    std::cin.get();
                    continue;
                }
                Book book = books[searchIndex];


                book.print();
                confirmation = getStringInput("Edit this record?");


                if (tolower(confirmation[0]) == 'y') {
                    clearScreen();
                    editBook(books, searchIndex);
                }

                break;
            }
            case 4: {
                while (true) {
                    std::string search;
                    char confirmation;
                    search =  getStringInput("Enter the name or the ISBN of the book you want to delete. 'cancel' to go back");
                    if (search == "cancel") {
                        break;
                    }
                    int searchIndex = lookUpBook(search, books, index);
                    if (searchIndex == -1) {
                        std::cout << "That book was not found, press enter to search again." << std::endl;
                        std::cin.get();
                        continue;
                    }

                    std::cout << "[FOUND]: " << books[searchIndex].getTitle()
                              << "\nAre you sure you want to delete this record? (y/n)\n";
                    std::cin.ignore(1000, '\n');
                    std::cin >> confirmation;

                    if (tolower(confirmation) == 'y') {
                        clearScreen();
                        deleteBook(books, searchIndex, index);
                    } else {
                        break;
                    }
                    confirmation = '\0';
                    std::cout << "Delete another book? (y/n)" << std::endl;
                    std::cin >> confirmation;

                    if (tolower(confirmation) == 'y') {
                        continue;
                    } else {
                        break;
                    }
                }
            }
                break;
            case 5:
                // return to main menu
                return;
            default:
                std::cout << "That is not a valid choice" << std::endl;
                std::cin.ignore().get();
                continue;
        }
    }
}



void addBook(Book books[20], int &index) {
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

    Book book;


    while (true) {
        clearScreen();
        std::cout << "-------------------------------------------------------------------------------------------\n"
                  << "                                 Serendipity Booksellers                                   \n"
                  << "                                      Add Book                                             \n"
                  << "                              Today's date: " << buffer << "\n"
                  << "                            Current Database Size: " << index << "                       \n"
                  << "                                                                                           \n"
                  << "         1. Enter book title          | --Title           " << newBookTitle << "\n"
                  << "         2. Enter ISBN                | --ISBN            " << newISBN << "\n"
                  << "         3. Enter Author              | --Author          " << newAuthor << "\n"
                  << "         4. Enter Publisher           | --Publisher       " << newPublisher << "\n"
                  << "         5. Enter Date                | --Date Added      " << newDate << "\n"
                  << "         6. Enter Quantity            | --Quantity        " << newQuantity << "\n"
                  << "         7. Enter Wholesale Cost      | --Wholesale Cost  $" << newWholesaleCost << "\n"
                  << "         8. Enter Retail Price        | --Retail Price    $" << newRetailPrice << "\n"
                  << "         9. Save book to inventory                                                         \n"
                  << "         0. Return to main menu                                                            \n"
                  << "                                                                                           \n"
                  << "-------------------------------------------------------------------------------------------\n";
        choice = getIntegerInput("Enter a number between 0-9");

        switch (choice) {
            case 1: {
                newBookTitle = getStringInput("Please enter the book name");
                break;
            }
            case 2: {
                while (true) {
                    std::string temp;
                    temp = getStringInput("Please enter the ISBN");
                    int searchIndex = lookUpBook(temp, books, index);
                    if (searchIndex > -1) {
                        std::cout << "That ISBN already exists in the database." << std::endl;
                        std::cin.get();
                        continue;
                    }
                    newISBN = temp;
                    break;
                }
                break;
            }
            case 3: {
                newAuthor = getStringInput("Please enter the author");
                break;
            }
            case 4: {
                newPublisher = getStringInput("Please enter the publisher");
                break;
            }
            case 5: {
                newDate = getStringInput("Please enter the date");
                break;
            }
            case 6: {
                newQuantity = getIntegerInput("Please enter the quantity on hand");
                break;
            }
            case 7: {
                newWholesaleCost = getDoubleInput("Please enter the wholesale cost");
                break;
            }
            case 8: {
                newRetailPrice =  getDoubleInput("Please enter the retail price");
                break;
            }
            case 9: {
                if (index >= 20) {
                    std::cout << "The database is already completely full." << std::endl;
                    std::cin.get();
                    break;
                }
                book.setTitle(newBookTitle);
                book.setISBN(newISBN);
                book.setAuthor(newAuthor);
                book.setPublisher(newPublisher);
                book.setDateAdded(newDate);
                book.setQuantity(newQuantity);
                book.setWholesaleCost(newWholesaleCost);
                book.setRetailPrice(newRetailPrice);

                books[index] = book;
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


int lookUpBook(string search, Book books[20], int &index) {
    for (int i = 0; i < index; i++) {
        Book book = books[i];
        const int titlePos = book.getTitle().find(search);
        const bool matchingISBN = book.getISBN() == search;

        if (titlePos > -1 || matchingISBN) {
            return i;
        }
    }
    return std::string::npos;
}

void editBook(Book books[20], int &index) {
    int choice;
    char date[60];
    getDate(date);

    while (true) {
        clearScreen();
        Book book = books[index];
        std::cout << "-------------------------------------------------------------------------------------------\n"
                  << "                                 Serendipity Booksellers                                   \n"
                  << "                                      Edit Book                                            \n"
                  << "                              Today's date: " << date << "\n"
                  << "                            Current Database Size: " << index << "                       \n"
                  << "                                                                                           \n"
                  << "         1. Edit Book Title                | --Title           " << book.getTitle() << "\n"
                  << "         2. Edit ISBN                      | --ISBN            " << book.getISBN() << "\n"
                  << "         3. Edit Author                    | --Author          " << book.getAuthor() << "\n"
                  << "         4. Edit Publisher                 | --Publisher       " << book.getPublisher() << "\n"
                  << "         5. Edit Date                      | --Date Added      " << book.getDateAdded() << "\n"
                  << "         6. Edit Quantity                  | --Quantity        " << book.getQuantity() << "\n"
                  << "         7. Edit Wholesale Cost            | --Wholesale Cost  $" << book.getWholesaleCost()
                  << "\n"
                  << "         8. Edit Retail Price              | --Retail Price    $" << book.getRetailPrice() << "\n"
                  << "         0. Return to Main Menu                                                            \n"
                  << "                                                                                           \n"
                  << "-------------------------------------------------------------------------------------------\n";
        choice = getIntegerInput("Enter a number between 0-9");

        // braces are reqired to keep the context
        switch (choice) {
            case 1: {
                book.setTitle(getStringInput("Please enter the book name"));
                break;
            }
            case 2: {
                while (true) {
                    std::string temp;
                    temp = getStringInput("Please enter the ISBN");
                    int searchIndex = lookUpBook(temp, books, index);
                    if (searchIndex > -1) {
                        std::cout << "That ISBN already exists in the database." << std::endl;
                        continue;
                    }
                    book.setISBN(temp);
                    break;
                }
                break;
            }
            case 3: {
                book.setAuthor(getStringInput("Please enter the author"));
                break;
            }
            case 4: {
                book.setPublisher(getStringInput("Please enter the publisher"));
                break;
            }
            case 5: {
                book.setDateAdded(getStringInput("Please enter the date"));
                break;
            }
            case 6: {
                book.setQuantity(getIntegerInput("Please enter the quantity on hand"));
                break;
            }
            case 7: {
                book.setWholesaleCost(getDoubleInput("Please enter the wholesale cost"));
                break;
            }
            case 8: {
                book.setRetailPrice(getDoubleInput("Please enter the retail price"));
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

void deleteBook(Book books[20], int deleteIndex, int index) {
    for (int i = deleteIndex; i < index - 1; i++) {
        Book targetBook = books[i + 1];
        Book currentBook = books[i];
        currentBook.setTitle(targetBook.getTitle());
        currentBook.setISBN(targetBook.getISBN());
        currentBook.setAuthor(targetBook.getAuthor());
        currentBook.setPublisher(targetBook.getPublisher());
        currentBook.setDateAdded(targetBook.getDateAdded());
        currentBook.setQuantity(targetBook.getQuantity());
        currentBook.setWholesaleCost(targetBook.getWholesaleCost());
        currentBook.setRetailPrice(targetBook.getRetailPrice());
    }
    index--;
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
