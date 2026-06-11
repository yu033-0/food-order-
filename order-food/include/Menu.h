#pragma once 
#include <vector>
#include"MenuItem.h"
using namespace std;

class Menu
{
    private:
        vector<MenuItem> items;

       public:
        void addItem(string name,double price);
        void displayMenu();
        MenuItem*getItem(int index); 

};