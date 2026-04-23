#include "Order.h"
#include <iostream>
using namespace std;

void Order::addOrderItem(MenuItem* item, int qty) {
    orderList.push_back(OrderItem(item, qty));
}

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

void Order::clearOrder() {
    orderList.clear();
}