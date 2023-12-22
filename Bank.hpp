#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>

class Bank
{
private:
    std::string firstname;
    std::string lastname;
    int account_number;
    int telephone;
    float balance;
public:
    Bank();
    Bank(std::string, std::string, int, int, float);
    ~Bank();
    void set_firstname(std::string);
    void set_lastname(std::string);
    void set_account_number(int);
    void set_telephone(int);
    void set_balance(float);
    std::string get_firstname();
    std::string get_lastname();
    int get_account_number();
    int get_telephone();
    float get_balance();

    static void Add();
    void Show();
    void Search();
    void Edit();
    void Delete();
};

#endif