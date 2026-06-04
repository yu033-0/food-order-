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

string OrderSystem::getReceiptAsText() 
{
    return userOrder.getReceiptString(); 
}

// 🚀 讓大腦去清空 userOrder 記憶體
void OrderSystem::clearWebOrder() 
{
    userOrder.clearOrder();
}

// =================================================================
// 🚀 以下是新增給網頁前端對接的函數，直接加在原程式碼最下方即可
// =================================================================

string OrderSystem::getMenuAsJson() 
{
    string jsonStr = "[";
    jsonStr += "{\"id\":1,\"name\":\"經典牛肉堡\",\"price\":125},";
    jsonStr += "{\"id\":2,\"name\":\"麥香雞肉堡\",\"price\":95},";
    jsonStr += "{\"id\":3,\"name\":\"黃金薯條(L)\",\"price\":55},";
    jsonStr += "{\"id\":4,\"name\":\"冰鎮可樂\",\"price\":35}";
    jsonStr += "]"; 
    return jsonStr;
}

// 2. 實作 handleWebOrder：接收網頁按鈕傳來的資料並自動加入購物車
bool OrderSystem::handleWebOrder(const string& jsonBody) 
{
    try {
        // 解析網頁傳過來的 JSON 字串，尋找 "id": 和 "qty":
        size_t idPos = jsonBody.find("\"id\":");
        if (idPos == string::npos) return false;
        
        // 抓出 id 的數字（因為目前只有 1~4，直接抓下一格字元轉整數）
        int id = jsonBody[idPos + 5] - '0'; 

        size_t qtyPos = jsonBody.find("\"qty\":");
        if (qtyPos == string::npos) return false;
        
        // 抓出數量的數字
        int qty = jsonBody[qtyPos + 6] - '0'; 

        // 防呆機制：確保網頁傳來的餐點編號在 1 ~ 4 之間
        if (id >= 1 && id <= 4) 
        {
            // 呼叫你原本寫好的 getItem(choice - 1) 邏輯
            MenuItem* selected = restaurantMenu.getItem(id - 1);
            if (selected) 
            {
                // 呼叫你原本寫好的 addOrderItem 將餐點與數量存入購物車
                userOrder.addOrderItem(selected, qty);
                
                // 在 Linux 終端機即時印出訊息，Demo 給教授看時超方便！
                cout << "\n[網頁通知] 成功將 " << qty << " 份 【" << selected->name << "】 加入購物車！" << endl;
                return true;
            }
        }
    } 
    catch (...) {
        cout << "[系統錯誤] 解析網頁點餐資料時發生異常。" << endl;
    }
    return false;
}