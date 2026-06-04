#pragma once
#include "Menu.h"
#include "Order.h"
#include <string> // 💡 新增：因為要回傳和接收 JSON 字串
using namespace std;
class OrderSystem
{
private:
    Menu restaurantMenu;
    Order userOrder;

public:
    void initialize();
    void start(); // 舊的終端機互動功能可以留著不用刪
    string getReceiptAsText();
    void clearWebOrder();
    string getMenuAsJson();               // 讓 main.cpp 可以拿菜單轉給網頁
    bool handleWebOrder(const string& jsonBody); // 讓 main.cpp 把網頁的點餐資料傳進來
};