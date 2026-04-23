#include "OrderItem.h"

OrderItem::OrderItem(MenuItem* i, int q) : item(i), quantity(q) {}

double OrderItem::getSubtotal() 
{
    return item->price * quantity;
}