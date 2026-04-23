#pragma once
#include "Menu.h"
#include "Order.h"

class OrderSystem 
{
private:
    Menu restaurantMenu;
    Order userOrder;
public:
    void initialize(); 
    void start();     
};
