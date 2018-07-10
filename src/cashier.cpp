/* ***********************************************************
 * Project Name:  Serendipity
 * File Name: cashier.cpp
 * ***********************************************************
 * Creator's name and email: Ali Bingol (abingol0@ivc.edu)
 * Course-Section: CS1B
 * Creation Date: 6/19/2018
 * Date of Last Modification: 6/19/2018
 * ***********************************************************
 * Purpose: Prompting the user to purchase a book
 * ***********************************************************
 * Algorithm:
 *  Step 1: Prompt the user for different information
 *  Step 2: Save all of it inputs to a variable
 *  Step 3: Calculate the total based on purchase amount and tax
 * ***********************************************************
 *                      DATA DICTIONARY
 * 
 * CONSTANTS:
 * 
 * NAME                 DATA TYPE               VALUE
 * -------------        ------------            -----------
 * TAX                  const float             1.06
 * 
 * 
 * VARIABLES:
 * 
 * NAME                 DATA TYPE               VALUE
 * -------------        ------------            -----------
 * date                 std::string             
 * quantity             int
 * ISBN                 std::string
 * title                std::string
 * price                float
 */
#include <iostream>
#include "cashier.h"
#include <fstream>
#include <string>
#include <iomanip>
#include <invmenu.h>
#include "mainmenu.h"
#include "cashier.h"
#include <cstring>

using std::setw;

void cashier(Book books[20], int& index){
    Book basket[20];
    int basketSize = 0;

    std::string bookSelection;
    const float TAX = 1.06;

    do {
        clearScreen();
        
        bookSelection = getStringInput("Search Book ['back' to go back] > ");

        if (bookSelection == "back"){
            return;
        }

        const int bookIndex = lookUpBook(bookSelection, books, index);

        if (bookIndex == -1){
            std::cin.ignore(1000, '\n');
            std::cout << "That was not a valid choice... Press enter to return" << std::endl;
            std::cin.get();
            continue;
        }
        Book book = books[bookIndex];

        book.print();
        int amount = getIntegerInput("How much would you like to purchase?");

        clearScreen();
        const int bookAmount = book.getQuantity();
        if (amount > bookAmount){
            std::cout << "Could only find " << bookAmount << " copies of this book" << std::endl;
            amount = bookAmount;
        }

        book.setQuantity(amount);

        book.print();
        const bool isSure = getBooleanInput("Are you sure you want to purchase this book?");

        if (!isSure){
            continue;
        }

        basket[basketSize] = book;
        basketSize++;
        std::cout << setw(10) << "Qty" << setw(10) << "ISBN" << setw(10) << "Title"
                  << setw(10) << "Price" << setw(10) << "Total" << '\n';

        double basketTotal = 0;
        for (int i = 0 ; i < basketSize ; i++){

            double bookTotal = book.getRetailPrice() * book.getQuantity();
            basketTotal += bookTotal;

            std::cout << setw(10) << book.getQuantity()
                      << setw(10) << book.getISBN()
                      << setw(10) << book.getTitle()
                      << setw(10) << book.getRetailPrice()
                      << setw(10) << bookTotal << '\n';
        }

        double finalTax = basketTotal * (TAX - 1);
        double total = finalTax + basketTotal;

        std::cout << setw(10) << "Subtotal: " << basketTotal  << std::endl
                  << setw(10) << "Tax: " << finalTax << std::endl
                  << setw(10) << "Total: " << total << std::endl
                  << "Thanks for shopping at Serendipity" << std::endl;

        const bool again = getBooleanInput("Would you like to add another book? (y/n)");
        if (!again){
            return;
        }
    } while(true);
}
