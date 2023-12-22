#include "Bank.hpp"
#include "Menu.hpp"

int main()
{
    Menu menu;
    while(1) {
        menu.display_menu();
        std::cout << "\n**************************************\n" << std::endl;
    }
    return 0;
}