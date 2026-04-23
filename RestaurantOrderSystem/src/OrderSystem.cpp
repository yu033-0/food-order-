#include "OrderSystem.h"
#include <iostream>
using namespace std;
void OrderSystem::initialize() 
{
    restaurantMenu.addItem("經典牛肉堡", 125);
    restaurantMenu.addItem("麥香雞肉堡", 95);
    restaurantMenu.addItem("黃金薯條(L)", 55);
    restaurantMenu.addItem("冰鎮可樂", 35);
}

void OrderSystem::start()
 {
    int choice = -1;
    while (choice != 0) 
    {
        restaurantMenu.displayMenu();
        cout << "請輸入餐點編號點餐 (輸入 0 結帳並結束): ";
        cin >> choice;

        if (choice > 0) 
        {
            MenuItem* selected = restaurantMenu.getItem(choice - 1);
            if (selected) 
            {
                int qty;
                cout << "請輸入 " << selected->name << " 的數量: ";
                cin >> qty;
                userOrder.addOrderItem(selected, qty);
                cout << ">> 已加入購物車！" << std::endl;
            } 
            else 
            {
                cout << ">> 無此編號，請重新輸入。" << std::endl;
            }
        }
    }
    userOrder.printReceipt();
}