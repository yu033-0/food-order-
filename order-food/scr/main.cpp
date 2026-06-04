#include "OrderSystem.h"
#include "httplib.h"
#include <iostream>

using namespace std;

int main() {
    OrderSystem mySystem;
    mySystem.initialize(); 

    httplib::Server svr;
    // 💡 確保對準前端資料夾
    svr.set_mount_point("/", "./frontend"); 

    // 1. 網頁拿菜單
    svr.Get("/api/menu", [&](const httplib::Request&, httplib::Response& res) {
        string menuJson = mySystem.getMenuAsJson(); 
        res.set_content(menuJson, "application/json");
        res.set_header("Access-Control-Allow-Origin", "*");
    });

    // 2. 網頁送點餐
    svr.Post("/api/order", [&](const httplib::Request& req, httplib::Response& res) {
        bool success = mySystem.handleWebOrder(req.body); 
        if (success) {
            res.set_content("已加入購物車", "text/plain; charset=utf-8");
        } else {
            res.set_content("點餐失敗", "text/plain; charset=utf-8");
        }
        res.set_header("Access-Control-Allow-Origin", "*");
    });

    // 3. 🚀 新增：網頁即時獲取 C++ 記憶體裡的動態明細
    svr.Get("/api/receipt", [&](const httplib::Request&, httplib::Response& res) {
        string receiptText = mySystem.getReceiptAsText();
        res.set_content(receiptText, "text/plain; charset=utf-8");
        res.set_header("Access-Control-Allow-Origin", "*");
    });

    // 4. 🚀 新增：網頁確認結帳（終端機印明細，並清空購物車）
    svr.Post("/api/checkout", [&](const httplib::Request&, httplib::Response& res) {
        // 在 C++ 後端 Linux 終端機真的執行原本的列印
        cout << "\n[網頁點餐機通知] 收到結帳指令！正在終端機列印實體發票：" << endl;
        mySystem.start(); // 這會觸發 userOrder.printReceipt()
        
        // 結帳完後清空記憶體，方便下一個人點餐
        mySystem.clearWebOrder();
        
        res.set_content("結帳成功！實體收據已列印至 Linux 後端控制台。", "text/plain; charset=utf-8");
        res.set_header("Access-Control-Allow-Origin", "*");
    });

    cout << "期末專題伺服器正在運行：http://localhost:8080" << endl;
    svr.listen("0.0.0.0", 8080);
    return 0;
}