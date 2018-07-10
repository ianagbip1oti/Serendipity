#pragma once
#include <string>


class Book {
    /**
     * Don't want to stealthily include things
     * in the namespace of files that import this
     * header
     */

    std::string title;
    std::string isbn;
    std::string author;
    std::string publisher;
    std::string dateAdded;
    double wholesaleCost;
    double retailPrice;
    int quantity;
public:
    void setTitle(std::string);
    std::string getTitle();

    void setISBN(std::string);
    std::string getISBN();

    void setAuthor(std::string);
    std::string getAuthor();

    void setPublisher(std::string);
    std::string getPublisher();

    void setDateAdded(std::string);
    std::string getDateAdded();

    void setWholesaleCost(double);
    double getWholesaleCost();

    void setRetailPrice(double);
    double getRetailPrice();

    void setQuantity(int);
    int getQuantity();

    void print();
};
