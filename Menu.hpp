#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>

class Menu
{
private:
    int choice;
    int number_of_records;
public:
    Menu();
    ~Menu();

    void set_choice(int);
    int get_choice();
    void set_number_of_records(int);
    int get_number_of_records();
    void increment_number_of_record();

    void display_menu();
    void Show();
    void ShowAll();
};

#endif