#include <string>
#include "menu.h"
#include <iostream>
#include <windows.h>

Menu& Menu::setName(const std::string& name){
    this-> name = name;
    return *this;
}

Menu& Menu::addLink(const std::string& display, Menu* menu){
    this->links.emplace_back(display, menu);
    return *this;
}

void Menu::displayMenu(bool clear){
    if (clear){
        system("cls");
    }
    std::cout << "Menu: " << this->name << std::endl << std::endl;
    const int SIZE = this->links.size();
    for (int i = 0; i < SIZE; i++){
        // Starting at 1 because of user experience and what not
        std::cout << i + 1 << ": " << this->links[i].first << std::endl;
    }
    std::cout << std::endl;
}

Menu* Menu::navigate(int index){
    const int SIZE = this->links.size;
    if (index > SIZE || index < 0){
        // invalid navigation attempt
        return nullptr;
    }
    std::pair<std::string, Menu*> targetMenu = this->links.at(index);
    return targetMenu.second;
}

int Menu::pollInput() {
    int input;
    while (true){
        /* we want the screen to be cleared every time
         * though this doesn't really matter since it's
         * already a default parameter.
         */
        this->displayMenu(true);
        std::cout << "Please enter a number corresponding to the action you want to take:\t" << std::endl;
        std::cin >> input;
        if (std::cin.fail()){
            std::cout << "That is not a valid number, please enter an integer instead." << std::endl;
            system("pause");
            continue;
        }
        return input;
    }
}