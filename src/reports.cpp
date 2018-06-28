/* ***********************************************************
 * Project Name:               Serendipity
 * File Name:                  reports.cpp
 * ***********************************************************
 * Creator's name and email:   Ali Bingol (abingol0@ivc.edu)
 * Course-Section:             CS1B
 * Creation Date:              6/19/2018
 * Date of Last Modification:  6/19/2018
 * ***********************************************************
 * Purpose: Navigating through the reports menu
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
 * 
 * VARIABLES:
 * 
 * NAME                 DATA TYPE               VALUE
 * -------------        ------------            -----------
 */

#include <iostream>
#include "cashier.h"
#include "invmenu.h"
#include "reports.h"
#include "mainmenu.h"

void reports(){
    int choice;
    bool success;
    do {
        clearScreen();
        std::cout << "--------------------------------------------\n"
                  << "|         Serendipity Booksellers          |\n"  
                  << "|                 Reports                  |\n"  
                  << "|                                          |\n"  
                  << "|         1. Inventory Listing             |\n" 
                  << "|         2. Inventory Wholesale Value     |\n"
                  << "|         3. Inventory Retail Value        |\n"
                  << "|         4. Listing by Quantity           |\n" 
                  << "|         5. Listing by Cost               |\n"
                  << "|         6. Listing by Age                |\n"
                  << "|         7. Return to Main Menu           |\n"                  
                  << "|                                          |\n"                    
                  << "|         Enter a number between 1-7       |\n" 
                  << "|                                          |\n"
                  << "--------------------------------------------\n";
            
        success = getIntegerInput(choice);
        if (!success){
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }
        switch (choice){
        case 1:
            repListing();
            break;
        case 2:
            repWholesale();
            break;
        case 3:
            repRetail();
            break;
        case 4:
            repQty();
            break;
        case 5:
            repCost();
            break;
        case 6:
            repAge();
            break;
        case 7:
            return;
        }
    } while (success);
}


void repListing(){
    std::cout << "You selected Inventory Listing" << std::endl;
}

void repWholesale(){
    std::cout << "You selected Inventory Wholesale Value" << std::endl;
}

void repRetail(){
    std::cout << "You selected Inventory Retail Value" << std::endl;
}

void repCost(){
    std::cout << "You selected Listing By Cost" << std::endl;
}


void repQty(){
    std::cout << "You selected Listing By Quantity" << std::endl;
}

void repAge(){
    std::cout << "You selected Listing By Age" << std::endl;
}
