/* ***********************************************************
 * Project Name:               Serendipity
 * File Name:                  mainmenu.cpp
 * ***********************************************************
 * Creator's name and email:   Ali Bingol (abingol0@ivc.edu)
 * Course-Section:             CS1B
 * Creation Date:              6/19/2018
 * Date of Last Modification:  6/19/2018
 * ***********************************************************
 * Purpose: Nagivating through menus and adding a book * ***********************************************************
 * Algorithm:
 *  Step 1: Display the main menu for the user
 * ***********************************************************
 *                      DATA DICTIONARY
 * 
 * CONSTANTS:
 * 
 * NAME                 DATA TYPE               VALUE
 * -------------        ------------            -----------
 * DBSIZE               int                     20 
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

using std::string;
const int DBSIZE = 20;

int main() {
    string bookTitle[DBSIZE];
    string isbn[DBSIZE];
    string author[DBSIZE];
    string publisher[DBSIZE];
    string dateAdded[DBSIZE];
    int quantity[DBSIZE];
    double wholesaleCost[DBSIZE];
    double retailPrice[DBSIZE];
    int bookCount = 0;

    displayMainMenu(bookTitle, isbn, author, publisher, dateAdded, quantity, wholesaleCost, retailPrice, bookCount);
    // clearing the screen before exiting
    clearScreen();
    return 0;
}

void displayMainMenu(string bookTitle[DBSIZE], string isbn[DBSIZE], string author[DBSIZE], string publisher[DBSIZE],
                     string dateAdded[DBSIZE], int quantity[DBSIZE], double wholesaleCost[DBSIZE],
                     double retailPrice[DBSIZE], int &index) {

    int choice;
    bool success;
    while (true) {
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
                  << "--------------------------------------------" << std::endl;

        getIntegerInput("Enter a number between 1-4", choice);

        switch (choice) {
            case 1:
                cashier(bookTitle, isbn, author, publisher, dateAdded, quantity, wholesaleCost, retailPrice, index);
                break;
            case 2:
                invMenu(bookTitle, isbn, author, publisher, dateAdded, quantity, wholesaleCost, retailPrice, index);
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
    }
}

void clearScreen() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}


void getIntegerInput(const char *prompt, int &choice) {
    while (true) {
        std::cout << prompt << std::endl;
        int temp;
        std::cin >> temp;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "That was not a valid double... Press enter to return" << std::endl;
            std::cin.get();
            continue;
        }
        choice = temp;
        return;
    }

}


void getDoubleInput(const char *prompt, double &choice) {
    while (true) {
        std::cout << prompt << std::endl;
        double temp;
        std::cin >> temp;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "That was not a valid double... Press enter to return" << std::endl;
            std::cin.get();
            continue;
        }
        choice = temp;
        return;
    }
}


void getStringInput(const char *prompt, std::string &choice) {
    while (true) {
        std::cout << prompt << std::endl;
        // we need to clear the buffer from
        // the previous cin >> statements
        std::string temp;
        std::cin.ignore(1000, '\n');
        std::getline(std::cin, temp);
        if (temp.empty()) {
            std::cin.ignore(1000, '\n');
            std::cout << "That was not a valid choice... Press enter to return" << std::endl;
            std::cin.get();
            std::cin.clear();
            continue;
        }
        std::cin.clear();
        choice = temp;
        return;
    }
}


