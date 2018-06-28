/* ***********************************************************
 * Project Name:               Serendipity
 * File Name:                  mainmenu.cpp
 * ***********************************************************
 * Creator's name and email:   Ali Bingol (abingol0@ivc.edu)
 * Course-Section:             CS1B
 * Creation Date:              6/19/2018
 * Date of Last Modification:  6/19/2018
 * ***********************************************************
 * Purpose: Nagivating through menus and adding a book
 * ***********************************************************
 * Algorithm:
 *  Step 1: Display the main menu for the user
 * ***********************************************************
 *                      DATA DICTIONARY
 * 
 * CONSTANTS:
 * 
 * NAME                 DATA TYPE               VALUE
 * -------------        ------------            -----------
 * header               std::string[]           {"Number", "Location", "Description"}
 * cashier              std::string[]           {"1", "Cashier", "Goes to the cashier page"}
 * reports              std::string[]           {"2" ,"Reports", "Goes to the reports page"}
 * inventory            std::string[]           {"3", "Inventory", "Goes to the inventory page"}
 * 
 * 
 * VARIABLES:
 * 
 * NAME                 DATA TYPE               VALUE
 * -------------        ------------            -----------
 * choice               int                     null
 * success              bool                    null
 */

#include <iostream>
#include "mainmenu.h"
#include "cashier.h"
#include "invmenu.h"
#include "reports.h"
#include <cstdlib>

int main() {
    displayMainMenu();
    return 0;
}   

void displayMainMenu(){
    int choice;
    bool success;
    do {
        clearScreen();
        std::cout << "--------------------------------------------\n"
                  << "|         Serendipity Booksellers          |\n"  
                  << "|                Main Menu                 |\n"  
                  << "|                                          |\n"  
                  << "|         1. Cashier Module                |\n" 
                  << "|         2. Inventory Database Module     |\n"
                  << "|         3. Report Module                 |\n"
                  << "|         4. Exit                          |\n" 
                  << "|                                          |\n"
                  << "|         Enter a number between 1-4       |\n" 
                  << "|                                          |\n"
                  << "--------------------------------------------" << std::endl; 
            
        success = getIntegerInput(choice);
        if (!success){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }
        switch (choice){
        case 1:
            cashier();
            break;
        case 2:
            invMenu();
            break;
        case 3:
            reports();
            break;
        case 4:
            return;
        default:
            std::cout << "That is not a valid choice... Press Enter to continue" << std::endl;
            std::cin.ignore().get();
            continue;
        }
    } while (success);
}

void clearScreen(){
    #ifdef _WIN32
        std::system("cls");
    #else
        std::system("clear");
    #endif
}


bool getIntegerInput(int& choice){
    int temp;
    std::cin >> temp;
    if (std::cin.fail()){
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return false;
    }
    choice = temp;
    return true;
}



