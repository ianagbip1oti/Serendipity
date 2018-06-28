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
#include "mainmenu.h"
void getInput(const char* prompty, std::string& destination){
    using namespace std;
    cout << prompty << endl;
    cin.clear();
    cin.sync();
    getline(cin, destination);
}

void getInput(const char* prompty, int& destination){
    using namespace std;
    cout << prompty << endl;
    cin.clear();
    cin.sync();
    cin >> destination;
}

void cashier(){
    std::string bookTitle[20];
    std::string isbn[20];
    std::string author[20];
    std::string publisher[20];
    std::string dateAddded[20];
    
    int menuSelection;
    bool success;
    char choice;
    std::string date = "";
    int quantity = 0;
    std::string ISBN = "";
    std::string title = "";
    float price = 0.f;
    const float TAX = 1.06;
    do {
        if (date != "" && ISBN != "" && title != "" && quantity != 0 && price != 0.f){
            float subTotal = price * quantity;
            float finalTax = subTotal * TAX;
            float total = finalTax * subTotal;

            clearScreen();
    

            std::cout << "Date: " << date << "\n"
                      << "Quantity:  " << quantity << "\n"
                      << "ISBN: " << isbn << "\n"
                      << "Title: " << title << "\n"
                      << "Title " << price << "\n"
                      << "Thank you for shopping at serendipity\n\n";

            std::cout << "Subtotal: " << subTotal << std::endl
                      << "Tax: " << finalTax << std::endl
                      << "Total: " << total << std::endl;

            while (true){
                
                std::cout << "Would you like to enter another book? (y/n)" << std::endl;
                std::cin >> choice;
                if (std::cin.fail() || (tolower(choice) != 'n' && tolower(choice) != 'y')){
                    std::cin.clear();
                    std::cin.ignore(1000, '\n');
                    std::cout << "That is not a valid response" << std::endl;
                    continue;
                }
                else if (tolower(choice) == 'y'){
                    date = "";
                    ISBN = "";
                    title = "";
                    quantity = 0;
                    price = 0.f;
                    break;
                }
                else {
                    return;
                }
            }
        }

        clearScreen();
        

        std::cout << "         Serendipity Booksellers           \n" 
                  << "              Cashier Module               \n"
                  << "                                           \n"
                  << "         1. Enter publish Date         Current Date: " << date << "\n"                 
                  << "         2. Enter Desired Quantity     Current Quantity:  " << quantity << "\n"
                  << "         3. Enter the ISBN             Current ISBN: " << ISBN << "\n"                        
                  << "         4. Enter the Title            Current Title: " << title << "\n"                        
                  << "         5. Enter the Price            Current Price " << price << "\n"                         
                  << "         6. Back to the Main Menu         \n"
                  << "                                          \n"  
                  << "         Enter a number between 1-6       \n" 
                  << "                                          \n"; 
        
        success = getIntegerInput(menuSelection);
        switch (menuSelection){
        case 1:
            getInput("Please enter the date the book was published in.", date);
            break;
        case 2:
            getInput("Please enter the quantity.", quantity);
            break;
        case 3:
            std::cout << "Please enter the ISBN." << std::endl;
            std::cin.clear();
            std::cin.sync();
            std::getline(std::cin, ISBN);
            break;
        case 4:
            std::cout << "Please enter the title." << std::endl;
            std::cin.clear();
            std::cin.sync();
            std::getline(std::cin, title);
            break;
        case 5:
            std::cout << "Please enter the price." << std::endl;
            std::cin.clear();
            std::cin.sync();
            std::cin >> price;
            break;
        case 6:
            return;
        default:

            std::cout << "That is not a valid choice... Press Enter to continue" << std::endl;
            std::cin.ignore().get();
            continue;
        }
        
    } while(true);
    displayMainMenu();
}
