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
void invMenu(){

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
            addBook();
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


void addBook(){
    std::cout << "You selected Add Book" << std::endl;
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
