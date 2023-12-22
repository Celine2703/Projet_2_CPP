#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <fstream>
#include <sstream>

class Bank
{
private:
    std::string firstname;
    std::string lastname;
    int account_number;
    int telephone;
    double balance;
    int id_record;
public:
    Bank();
    Bank(std::string, std::string, int, int, double, int);
    ~Bank();
    void set_firstname(std::string);
    void set_lastname(std::string);
    void set_account_number(int);
    void set_telephone(int);
    void set_balance(double);
    std::string get_firstname();
    std::string get_lastname();
    int get_account_number();
    int get_telephone();
    double get_balance();
    int get_id_record();

    static Bank Add(int);
    static void Search();
    static void Edit();
    static void Delete();
};

#endif