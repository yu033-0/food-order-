#include"Menu.h"
#include <iostream>
#include <iomanip>
using namespace std;

void Menu::addItem(string name, double price) 
{
    items.push_back(MenuItem(name, price));
}

void Menu::displayMenu() {
    cout << "\n----------- 餐廳菜單 -----------" << std::endl;
    for (int i = 0; i < items.size(); ++i) 
    {
        cout << "[" << i + 1 << "] " << std::left << std::setw(18) 
                  << items[i].name << "$" << items[i].price << std::endl;
    }
    std::cout << "-------------------------------" << std::endl;
}

MenuItem* Menu::getItem(int index)
 {
    if (index >= 0 && index < (int)items.size()) 
    {
        return &items[index];
    }
    return nullptr;
}