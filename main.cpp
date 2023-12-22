#include "Bank.hpp"
#include "Menu.hpp"

int main()
{
    Menu menu;
    while(1) {
        menu.Init();
        menu.display_menu();
        std::cout << "\n**************************************\n" << std::endl;
    }
    return 0;
}