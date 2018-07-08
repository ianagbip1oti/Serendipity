#include "bookinfo.h"
#include <string>
#include <iostream>

void Book::setTitle(std::string newName) {
    title = newName;
}

std::string Book::getTitle() {
    return title;
}

void Book::setISBN(std::string newISBN) {

    isbn = newISBN;
}

std::string Book::getISBN() {
    return isbn;
}

void Book::setAuthor(std::string newAuthor) {
    author = newAuthor;
}

std::string Book::getAuthor(){
    return author;
}

void Book::setPublisher(std::string newPublisher) {
    publisher = newPublisher;
}

std::string Book::getPublisher() {
    return publisher;
}


void Book::setDateAdded(std::string newDate) {
    dateAdded = newDate;
}

std::string Book::getDateAdded() {
    return dateAdded;
}

void Book::setQuantity(int newAmount) {
    quantity = newAmount;
}

int Book::getQuantity() {
    return quantity;
}

void Book::setWholesaleCost(double newCost) {
    wholesaleCost = newCost;
}

double Book::getWholesaleCost() {
    return wholesaleCost;
}

void Book::setRetailPrice(double newPrice) {
    retailPrice = newPrice;
}

double Book::getRetailPrice(){
    return retailPrice;
}

void Book::print() {
    std::cout << "           Title: " << getTitle() << std::endl
              << "            ISBN: " << getISBN() << std::endl
              << "          Author: " << getAuthor() << std::endl
              << "       Publisher: " << getPublisher() << std::endl
              << "      Date Added: " << getDateAdded() << std::endl
              << "Quantity on hand: " << getQuantity() << std::endl
              << "  Wholesale Cost: $" << getWholesaleCost() << std::endl
              << "    Retail Price: $" << getRetailPrice() << std::endl;
}





