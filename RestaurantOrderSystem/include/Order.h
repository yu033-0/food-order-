#pragma once 
#include <vector>
#include"OrderItem.h"
using namespace std;

class Order 
{
    private:
        vector<OrderItem>orderList;
    public:
        void addOrderItem(MenuItem*item,int qty);
        void printReceipt();
        void clearOrder ();
};