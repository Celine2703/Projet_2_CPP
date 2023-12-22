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
    std::string account_number;
    std::string telephone;
    std::string balance;
    int id_record;
public:
    Bank();
    Bank(std::string, std::string, int, int, double, int);
    ~Bank();
    int get_id_record();

    static Bank Add(int);
    static void Edit();
    static int Delete();
};

#endif