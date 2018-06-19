#pragma once
#include "menu.h"
#include "book.h"
#include <vector>

class BookMenu : Menu {
    std::vector<Book> books;
};