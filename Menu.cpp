#include "Menu.hpp"
#include "Bank.hpp"

Menu::Menu()
{
    choice = 0;
}

Menu::~Menu() {}

void Menu::set_choice(int choice)
{
    this->choice = choice;
}

int Menu::get_choice()
{
    return choice;
}

void Menu::set_number_of_records(int number_of_records)
{
    this->number_of_records = number_of_records;
}

int Menu::get_number_of_records()
{
    return number_of_records;
}

void Menu::increment_number_of_record()
{
    ++number_of_records;
}

void Menu::display_menu()
{
    std::cout << "***Acount Information System***" << std::endl;
    std::cout << "Select one option below" << std::endl;
    std::cout << "1-->Add record to file" << std::endl;
    std::cout << "2-->Show record from file" << std::endl;
    std::cout << "3-->Search record from file" << std::endl;
    std::cout << "4-->Update record" << std::endl;
    std::cout << "5-->Delete record" << std::endl;
    std::cout << "6-->Quit" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cout << std::endl;
    switch (choice)
    {
    case 1:
        Bank::Add(number_of_records);
        break;
    // case 2:
    //     Show();
    //     break;
    // case 3:
    //     Search();
    //     break;
    // case 4:
    //     Edit();
    //     break;
    // case 5:
    //     Delete();
    //     break;
    // case 6:
    //     std::cout << "Thank you for using our system" << std::endl;
    //     break;
    default:
        std::cout << "Wrong choice" << std::endl;
        break;
    }
}
