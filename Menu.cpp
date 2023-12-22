#include "Menu.hpp"
#include "Bank.hpp"
#include <filesystem>
#include <dirent.h>


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

void Menu::Init() {
    std::string path = "./bank_records/";
    int compteur = 0;
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir(path.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_REG)
            {
                compteur++;
            }
        }
        closedir(dir);
    } else {
        std::cerr << "Erreur: Impossible d'ouvrir le répertoire." << '\n';
    }

    this->set_number_of_records(compteur);
}

void Menu::display_menu()
{
    std::cout << "***Account Information System***" << std::endl;
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

    choice = atoi(demanderNombreEtVerifier("Enter your choice: ").c_str());
    if (std::cin.eof()) {
        std::cout << "Thank you for using our system" << std::endl;
        exit(0);
    }
    while (choice < 1 || choice > 7) {
            choice = atoi(demanderNombreEtVerifier("Enter your choice: ").c_str());
            if (std::cin.eof()) {
                std::cout << "Thank you for using our system" << std::endl;
                exit(0);
            }
    }

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
    case 3:
        Search();
        break;
    case 4:
        Bank::Edit();
        break;
    case 5:
        this->set_number_of_records(this->get_number_of_records() - Bank::Delete());
        break;
    case 6:
        ShowAll();
        break;
    case 7:
        std::cout << "Thank you for using our system" << std::endl;
        exit(0);
        break;
    default:
        std::cout << "Wrong choice" << std::endl;
        break;
    }
}

void Menu::Show() 
{
    std::string account_number;
    account_number = demanderNombreEtVerifier("Enter Account Number: ");
    std::string firstname;
    firstname = demanderStringEtVerifier("Enter First Name: ");
    std::string lastname;
    lastname = demanderStringEtVerifier("Enter Last Name: ");
    int fichier = 0;
    int compteur_fichier = 0;
    while(this->get_number_of_records() >= 0 && fichier < this->get_number_of_records())
    {
        std::string filename = "./bank_records/record_" + std::to_string(compteur_fichier) + ".txt";
        std::ifstream infile(filename);
        std::cout << std::endl;

        if (!infile) {
            fichier++;
            continue;
        }

        std::string Accountline;
        std::getline(infile, Accountline);
        std::string firstnameLine;
        std::getline(infile, firstnameLine);
        std::string LastnameLine;
        std::getline(infile, LastnameLine);
        std::string telephone;
        std::getline(infile, telephone);
        std::string balance;
        std::getline(infile, balance);

        if (Accountline == account_number && firstname == firstnameLine 
                && LastnameLine == lastname) {
            std::cout << "Balance: " << balance << std::endl;
            infile.close();
            return ;
        }

        infile.close();
        fichier++;

    }
    std::cout << "No Account Found\n" << std::endl;
}

void Menu::ShowAll() {

    int fichier = 0;
    int compteur_fichier = 0;
    while(this->get_number_of_records() >= 0 && fichier < this->get_number_of_records())
    {
        std::string filename = "./bank_records/record_" + std::to_string(compteur_fichier) + ".txt";
        std::ifstream infile(filename);
        compteur_fichier++;

        if (!infile) {
            continue;
        }

        std::cout << "*** File Name: " << "record_" + std::to_string(fichier) + ".txt" << " ***\n" << std::endl;

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


void Menu::Search() {
    static int firsttry = 0;

    if (firsttry == 0) {
        firsttry++;
        std::cout << "number of records: " << this->get_number_of_records() << std::endl;
        return;
    }
    std::string register_id;
    register_id = demanderNombreEtVerifier("Enter File ID: ");
    
    std::string filename = "./bank_records/record_" + register_id + ".txt";
    std::ifstream infile(filename);
    std::cout << std::endl;
    if (!infile) {
        std::cerr << "Erreur d'ouverture ! Fichier introuvable!!" << std::endl;
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
    std::cout << std::endl;


    infile.close();
}


std::string Menu::demanderNombreEtVerifier(std::string message) {
    std::cout << message;
    while (!std::cin.eof()) {
        std::string saisie;
        if (std::getline(std::cin, saisie)) {
            if (saisie.size() > 0 && std::all_of(saisie.begin(), saisie.end(), ::isdigit)) {
                return saisie;
            }
        }
        else {
                if (!std::cin.eof())
                    std::cerr << "Erreur de saisie. Réessayez.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore le reste de la ligne
        }
    }
    return "";
}

std::string Menu::demanderStringEtVerifier(std::string message) {
    std::string saisie;

    while (!std::cin.eof()) {
        std::cout << message;
        if (std::getline(std::cin, saisie)) {
            // Vérifie si l'entrée n'est pas vide
            if (!saisie.empty()) {
                return saisie;
            }
        } else {
                // Erreur de saisie, réinitialise l'état de cin et ignore l'entrée actuelle
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Erreur de saisie. Veuillez réessayer.\n";
        }
    }
    return "";
}
