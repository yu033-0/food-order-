#pragma once
#include "Menu.h"
#include "Order.h"
#include <string> // 💡 新增：因為要回傳和接收 JSON 字串

class OrderSystem
{
private:
    Menu restaurantMenu;
    Order userOrder;

public:
    void initialize();
    void start(); // 舊的終端機互動功能可以留著不用刪

    // 🚀 新增：專屬網頁對接的 Public 函數
    std::string getMenuAsJson();               // 讓 main.cpp 可以拿菜單轉給網頁
    bool handleWebOrder(const std::string& jsonBody); // 讓 main.cpp 把網頁的點餐資料傳進來
};