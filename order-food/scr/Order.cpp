#include "Order.h"
#include <iostream>
#include <string> // 確保可以使用 to_string

using namespace std;

// 1. 加入餐點品項
void Order::addOrderItem(MenuItem* item, int qty) {
    orderList.push_back(OrderItem(item, qty));
}

// 2. 原本的舊文字版列印功能（OrderSystem::start 結帳時會呼叫它）
// 💡 就是這裡！剛剛可能不小心漏掉它了，現在把它補回來！
void Order::printReceipt() {
    cout << "\n======= 您的點餐明細 =======" << endl;
    double total = 0;
    for (auto& oi : orderList)
    {
        double sub = oi.getSubtotal();
        cout << oi.item->name << " x " << oi.quantity << " = $" << sub << endl;
        total += sub;
    }
    cout << "---------------------------" << endl;
    cout << "總計總額: $" << total << endl;
    cout << "===========================\n" << endl;
}

// 3. 清空購物車
void Order::clearOrder() {
    orderList.clear();
}

// 4. 新增的網頁專用動態字串回傳功能（網頁右邊面板會呼叫它）
string Order::getReceiptString() 
{
    if (orderList.empty()) {
        return "暫無點餐資料。";
    }

    string res = "======= 您的點餐明細 =======\n";
    double total = 0;
    
    for (auto& oi : orderList)
    {
        double sub = oi.getSubtotal();
        res += oi.item->name + " x " + to_string(oi.quantity) + " = $" + to_string((int)sub) + "\n";
        total += sub;
    }
    
    res += "---------------------------\n";
    res += "總計總額: $" + to_string((int)total) + "\n";
    res += "===========================\n";
    
    return res;
}