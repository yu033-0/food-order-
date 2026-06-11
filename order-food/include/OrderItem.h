#pragma once 
#include "MenuItem.h"

class OrderItem
{
    public :
        MenuItem*item;
        int quantity;

        OrderItem(MenuItem*i,int q);
       double getSubtotal();
    
};