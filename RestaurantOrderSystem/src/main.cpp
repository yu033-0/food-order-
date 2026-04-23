#include "OrderSystem.h"
#include <iostream>

using namespace std;

int main() 
{
    OrderSystem mySystem;
    mySystem.initialize();
    mySystem.start();

    cout << "感謝使用點餐系統，再見！" << endl;
    
    return 0;
}
