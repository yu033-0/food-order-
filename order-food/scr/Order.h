#pragma once 
#include <vector>
#include "OrderItem.h"
#include <string> // 💡 新增：因為要回傳明細字串
using namespace std;

class Order 
{
    private:
        vector<OrderItem> orderList;
    public:
        void addOrderItem(MenuItem* item, int qty);
        void printReceipt();
        void clearOrder();
        
        // 🚀 新增這行：讓網頁前端可以直接抓到真正的即時明細字串
        string getReceiptString(); 
};