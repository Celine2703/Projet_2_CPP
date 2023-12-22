#include "Menu.hpp"
#include "Bank.hpp"

Menu::Menu()
{
    choice = 0;
    number_of_records = 0;
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
    std::cout << std::endl;
    std::cout << "Select one option below" << std::endl;
    std::cout << "1-->Add record to file" << std::endl;
    std::cout << "2-->Show record from file" << std::endl;
    std::cout << "3-->Search record from file" << std::endl;
    std::cout << "4-->Update record" << std::endl;
    std::cout << "5-->Delete record" << std::endl;
    std::cout << "6-->Show all records" << std::endl;
    std::cout << "7-->Quit" << std::endl;
    std::cout << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cout << std::endl;
    switch (choice)
    {
    case 1:
        Bank::Add(number_of_records);
        increment_number_of_record();
        break;
    case 2:
        Show();
        break;
    // case 3:
    //     Search();
    //     break;
    case 4:
        Bank::Edit();
        break;
    case 5:
        Bank::Delete();
        break;
    case 6:
        ShowAll();
        break;
    // case 6:
    //     std::cout << "Thank you for using our system" << std::endl;
    //     break;
    default:
        std::cout << "Wrong choice" << std::endl;
        break;
    }
}

void Menu::Show() {

    std::cout << "Enter Account Number: ";
    int fichier;
    std::cin >> fichier;
    std::string filename = "./bank_records/record_" + std::to_string(fichier) + ".txt";
    std::ifstream infile(filename);
    std::cout << std::endl;

    if (!infile) {
        std::cerr << "Error opening file for reading." << std::endl;
        return;
    }

    std::string line;
    std::getline(infile, line);
    std::cout << "Account Number: " << line << std::endl;
    std::getline(infile, line);
    std::cout << "First Name: " << line << std::endl;
    std::getline(infile, line);
    std::cout << "Last Name: " << line << std::endl;
    std::getline(infile, line);
    std::cout << "Telephone: " << line << std::endl;
    std::getline(infile, line);
    std::cout << "Balance: " << line << std::endl;

    infile.close();
}

void Menu::ShowAll() {

    int fichier = 0;

    while(this->get_number_of_records() >= 0 && fichier < this->get_number_of_records())
    {
        std::string filename = "./bank_records/record_" + std::to_string(fichier) + ".txt";
        std::ifstream infile(filename);

         if (!infile) {
            continue;
        }

        std::cout << "*** File Name: " << filename << " ***\n" << std::endl;

        std::string line;
        std::getline(infile, line);
        std::cout << "Account Number: " << line << std::endl;
        std::getline(infile, line);
        std::cout << "First Name: " << line << std::endl;
        std::getline(infile, line);
        std::cout << "Last Name: " << line << std::endl;
        std::getline(infile, line);
        std::cout << "Telephone: " << line << std::endl;
        std::getline(infile, line);
        std::cout << "Balance: " << line << std::endl;
        std::cout << std::endl;

        infile.close();
        fichier++;
    }
}
