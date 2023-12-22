#include "Bank.hpp"

Bank::Bank()
{
    firstname = "";
    lastname = "";
    account_number = 0;
    telephone = 0;
    balance = 0;
    id_record = -1;
}

Bank::Bank(std::string firstname, std::string lastname, int account_number, int telephone, double balance, int id_record)
{
    this->firstname = firstname;
    this->lastname = lastname;
    this->account_number = account_number;
    this->telephone = telephone;
    this->balance = balance;
    this->id_record = id_record;
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

void Bank::set_balance(double balance)
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

double Bank::get_balance()
{
    return balance;
}

int Bank::get_id_record()
{
    return id_record;
}

Bank Bank::Add(int number_of_records) {
    std::ofstream outfile("record.bank" + number_of_records, std::ios::binary | std::ios::app);

    if (!outfile) {
        std::cerr << "Error opening file for writing." << std::endl;
        return Bank();
    }

    Bank bank;  // Créez une instance locale de Bank

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

    // Écriture de l'objet Bank actuel dans le fichier
    outfile.write(reinterpret_cast<char *>(&bank), sizeof(Bank));

    outfile.close();

    return bank;
}

void Bank::Show() {
    std::ifstream infile("record.bank", std::ios::binary);

    if (!infile) {
        std::cerr << "Error opening file for reading." << std::endl;
        return;
    }

    Bank bank;  // Créez une instance locale de Bank

    std::cout << "\n****Data from file****" << std::endl;

    // Lecture de l'objet Bank actuel dans le fichier
    while (infile.read(reinterpret_cast<char *>(&bank), sizeof(Bank))) {
        std::cout << "Account Number: " << bank.account_number << std::endl;
        std::cout << "First Name: " << bank.firstname << std::endl;
        std::cout << "Last Name: " << bank.lastname << std::endl;
        std::cout << "Telephone Number: " << bank.telephone << std::endl;
        std::cout << "Balance: " << bank.balance << std::endl;
        std::cout << std::endl;
    }

    infile.close();
}
