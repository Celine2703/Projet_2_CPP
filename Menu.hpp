#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>

class Menu
{
private:
    int choice;
public:
    Menu();
    ~Menu();
    void set_choice(int);
    int get_choice();
    void display_menu();
};

#endif