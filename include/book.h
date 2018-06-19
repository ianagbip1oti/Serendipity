#pragma once
#include <string>

class Book {
public:
    int ISBN;
    std::string title;
    std::string author;
    std::string publisher;
    /**
     * I'm guessing that this value can't
     * be before 1970 so we don't have to 
     * worry about the unix epoch messing
     * up the date
     */
    int dateAdded;
    int quantity;
};