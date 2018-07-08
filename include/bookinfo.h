#pragma once
#include <string>


class Book {
    /**
     * Don't want to stealthily include things
     * in the namespace of files that import this
     * header
     */
    using std::string;

    string title;
    string isbn;
    string author;
    string publisher;
    string dateAdded;
    double wholesaleCost;
    double retailPrice;
    int quantity;
public:
    void setTitle(string);
    std::string getTitle();

    void setISBN(string);
    std::string getISBN();

    void setAuthor(string);
    std::string getAuthor();

    void setPublisher(string);
    std::string getPublisher();

    void setDateAdded(string);
    std::string getDateAdded();

    void setWholesaleCost(double);
    double getWholesaleCost();

    void setRetailPrice(double);
    double getRetailPrice();

    void setQuantity(int);
    int getQuantity();

    void print();
};