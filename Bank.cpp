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
    // Convertir le nombre d'enregistrements en une chaîne de caractères
    std::string record_suffix = std::to_string(number_of_records);

    // Créer le nom du fichier en ajoutant la chaîne de caractères au nom de base
    std::string filename = "./bank_records/record_" + record_suffix + ".txt";

    // Ouvrir le fichier en mode binaire
    std::ofstream outfile(filename);

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

    if(outfile.is_open()) {
        outfile << bank.account_number << std::endl;
        outfile << bank.firstname << std::endl;
        outfile << bank.lastname << std::endl;
        outfile << bank.telephone << std::endl;
        outfile << bank.balance << std::endl;
    } else {
        std::cerr << "Error opening file for writing." << std::endl;
    }

    outfile.close();

    return bank;
}

void Bank::Edit() {
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
    std::string AccountNumber = line;
    std::getline(infile, line);
    std::cout << "First Name: " << line << std::endl;
    std::getline(infile, line);
    std::cout << "Last Name: " << line << std::endl;
    std::getline(infile, line);
    std::cout << "Telephone: " << line << std::endl;
    std::getline(infile, line);
    std::cout << "Balance: " << line << std::endl;

    infile.close();

    std::cout << "\n\nEnter New Data: " << std::endl;

    std::cout << "Enter First Name: ";
    std::string firstname;
    std::cin >> firstname;
    std::cout << "Enter Last Name: ";
    std::string lastname;
    std::cin >> lastname;
    std::cout << "Enter Telephone Number: ";
    int telephone;
    std::cin >> telephone;
    std::cout << "Enter Balance: ";
    int balance;
    std::cin >> balance;

    std::ofstream outfile(filename);

    if (!outfile) {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }

    if(outfile.is_open()) {
        outfile << AccountNumber << std::endl;
        outfile << firstname << std::endl;
        outfile << lastname << std::endl;
        outfile << telephone << std::endl;
        outfile << balance << std::endl;
    } else {
        std::cerr << "Error opening file for writing." << std::endl;
    }

    outfile.close();
}

void Bank::Delete() {
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
    std::string AccountNumber = line;
    std::getline(infile, line);
    std::cout << "First Name: " << line << std::endl;
    std::getline(infile, line);
    std::cout << "Last Name: " << line << std::endl;
    std::getline(infile, line);
    std::cout << "Telephone: " << line << std::endl;
    std::getline(infile, line);
    std::cout << "Balance: " << line << std::endl;

    infile.close();

    std::cout << "\n\nAre you sure you want to delete this record? (y/n): ";
    char choice;
    std::cin >> choice;

    if(choice == 'y') {
        std::remove(filename.c_str());
        std::cout << "Record deleted successfully." << std::endl;
    }
}

void Bank::Search() {
    std::cout << "Enter Account Number: ";
    int account_number;
    std::cin >> account_number;
    int fichier = 0;

    while(this->get_number_of_records() >= 0 && fichier < this->get_number_of_records())
    {
        std::string filename = "./bank_records/record_" + std::to_string(fichier) + ".txt";
        std::ifstream infile(filename);
        std::cout << std::endl;

        if (!infile) {
            continue;
        }



    }


    std::string line;
    std::getline(infile, line);
    if (line == account_number) {
    
    }

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