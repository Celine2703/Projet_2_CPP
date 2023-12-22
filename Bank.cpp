#include "Bank.hpp"

Bank::Bank()
{
    firstname = "";
    lastname = "";
    account_number = 0;
    telephone = 0;
    balance = 0;
}

Bank::Bank(std::string firstname, std::string lastname, int account_number, int telephone, float balance)
{
    this->firstname = firstname;
    this->lastname = lastname;
    this->account_number = account_number;
    this->telephone = telephone;
    this->balance = balance;
}

Bank::~Bank() {}

void Bank::set_firstname(std::string firstname)
{
    this->firstname = firstname;
}

void Bank::set_lastname(std::string lastname)
{
    this->lastname = lastname;
}

void Bank::set_account_number(int account_number)
{
    this->account_number = account_number;
}

void Bank::set_telephone(int telephone)
{
    this->telephone = telephone;
}

void Bank::set_balance(float balance)
{
    this->balance = balance;
}

std::string Bank::get_firstname()
{
    return firstname;
}

std::string Bank::get_lastname()
{
    return lastname;
}

int Bank::get_account_number()
{
    return account_number;
}

int Bank::get_telephone()
{
    return telephone;
}

float Bank::get_balance()
{
    return balance;
}

void Bank::Add()
{
    Bank bank;
    std::ofstream outfile;
    outfile.open("record.bank", std::ios::binary | std::ios::app);
    std::cout << "Enter Account Number: ";
    std::cin >> bank.account_number;
    std::cout << "Enter First Name: ";
    std::cin >> bank.firstname;
    std::cout << "Enter Last Name: ";
    std::cin >> bank.lastname;
    std::cout << "Enter Telephone Number: ";
    std::cin >> bank.telephone;
    std::cout << "Enter Balance: ";
    std::cin >> bank.balance;
    outfile.write(reinterpret_cast<char *>(&bank), sizeof(Bank));
    outfile.close();
}
