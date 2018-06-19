#pragma once
#include "menu.h"
#include <vector>
#include <map>


class Menu {
protected:
    /**
     * Private constructor to prevent initiation of a new 
     * Menu object since it's a singleton
     */
    Menu(){};
public: 
    /* 
    * Storing the links in a vector instead of something
    * like a map because we need to be able to access it 
    * via an integer index which isn't really possible with maps
    */
    std::vector<std::pair<std::string, Menu*>> links;
    std::string name;
    /**:not
     * It would make more sense to put this as an argument 
     * constructor but a menu should be a singleton 
     * (even though that's technically a bad design pattern) 
     * you can't do constructor arguments for those
     */
    Menu& setName(const std::string&);
    /**
     * Returning Menu* to be able to chain the method
     */
    Menu& addLink(const std::string&, Menu*);
    virtual void displayMenu(bool = true);
    virtual int pollInput();
    /**
     * Returning a pointer  since we can't guarantee that
     * the navigation will be successful
     */
    Menu* navigate(int);
};