#include <iostream>
#include <vector>
#include <windows.h>
#include "mainmenu.h"
#include "cashier.h"
#include "invmenu.h"

int main(int arg, char* argv[]) {
    MainMenu mainMenu;
    CashierMenu cashierMenu;
    InventoryMenu inventoryMenu;

    inventoryMenu.setName("Inventory Menu")
        .addLink("Main Menu", &mainMenu)
        .addLink("Cashier", &cashierMenu)
        .addLink("Books", nullptr);

    cashierMenu.setName("Cashier Menu")
        .addLink("Main Menu", &mainMenu)
        .addLink("Inventory", &inventoryMenu)
        .addLink("Check Out", nullptr)
        .addLink("Shopping Card", nullptr);

    mainMenu.setName("Main Menu")
        .addLink("Cashier", &cashierMenu)
        .addLink("Inventory", &inventoryMenu)
        .addLink("Reports", nullptr);

    Menu* currentMenu = &mainMenu;
    /**z`
     * chances are this shouldn't be a member of the menu 
     * abstract class but rather a utility function since
     * we can't really poll on a menu that isn't 
     */
    while (true){
        const int input = currentMenu->pollInput();
        auto destination = currentMenu->navigate(input);
        if (destination == nullptr){
            std::cout << "That is not a valid"
        }
    }
}
