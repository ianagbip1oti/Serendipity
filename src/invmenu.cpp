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
             string dateAdded[20], int quantity[20], double wholesaleCost[20], double retailPrice[20]){

    int choice;
    bool success;
    do {
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
                  << "|         Enter a number between 1-5       |\n" 
                  << "|                                          |\n"
                  << "--------------------------------------------" << std::endl; 
        success = getIntegerInput(choice);

        if (!success){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "That was not a valid answer" << std::endl;
            std::cin.get();
            continue;
        }

        switch (choice){
        case 1:
            lookUpBook();
            break;
        case 2:
            addBook(bookTitle, isbn, author, publisher, dateAdded, quantity, wholesaleCost, retailPrice);
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

    } while(!success);
}


void addBook(string bookTitle[20], string isbn[20], string author[20], string publisher[20],
             string dateAdded[20], int quantity[20], double wholesaleCost[20], double retailPrice[20], int size){

    string newBookTitle = "EMPTY";
    string newISBN = "EMPTY";
    string newAuthor = "EMPTY";
    string newPublisher = "EMPTY";
    string newDate = "EMPTY";
    int newQuantity;
    double newWholesaleCost;
    double newRetailPrice;
    bool success;
    int choice;
    std::cout << "You selected Add Book" << std::endl;
    do {
        clearScreen();
        std::cout << "-------------------------------------------\n"
                  << "|         Serendipity Booksellers          \n"  
                  << "|                 Add Book                 \n"  
                  << "|                                          \n"  
                  << "|         1. Enter book title       | --Title " << newBookTitle  << "\n" 
                  << "|         2. Enter ISBN             | --ISBN " << newISBN <<  "\n"
                  << "|         3. Enter Author           | --Author " << newAuthor << "\n"
                  << "|         4. Enter Publisher        | --Publisher " << newPublisher "\n" 
                  << "|         5. Enter Date             | --Date Added "  << newDate  << "\n"
                  << "|                                          \n"
                  << "|         Enter a number between 1-5       \n" 
                  << "|                                          \n"
                  << "--------------------------------------------" << std::endl; 
        success = getIntegerInput(choice);

        if (!success){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "That was not a valid choice... Press enter to return" << std::endl;
            std::cin.get();
            continue;
        }

        switch (choice){
        case 1:

            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            return;
        default:
            std::cout << "That is not a valid choice" << std::endl;
            std::cin.ignore().get();
            continue;
        }

    } while(!success);

    
}

void lookUpBook(){
    std::cout << "You selected Look Up Book" << std::endl;
}

void editBook(){
    std::cout << "You selected Edit Book" << std::endl;
}

void deleteBook(){
    std::cout << "You selected Delete Book" << std::endl;
}
