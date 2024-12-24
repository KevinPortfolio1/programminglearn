/*

C++ 例外處理（Exception Handling）機制是用來捕捉和處理程式執行時的錯誤。
這樣可以讓程式在發生錯誤時不會突然崩潰，而是能夠適當處理錯誤並做出反應。
C++ 例外處理的基本結構包括 try、throw 和 catch。這裡會提供一個簡單的程式範例以及如何將其應用於實際情況的討論。
C++ 例外處理 基本結構
    try 區塊：包含可能會拋出例外的程式碼。
    throw 關鍵字：用來拋出例外物件。
    catch 區塊：用來捕捉並處理拋出的例外。

實際應用

    資料庫操作：在與資料庫進行交互時，可能會遇到如連接失敗、查詢錯誤等情況。
	可以用例外處理來捕捉這些錯誤並做適當處理，例如重試、記錄錯誤、通知使用者等。

    檔案處理：當開啟、讀取或寫入檔案時，可能會遇到檔案不存在、無法讀寫等問題，
	這些問題可以透過例外處理機制來捕捉。

    網路通信：在網路應用程式中，可能會遇到連接中斷、超時等問題。
	這些錯誤可以使用例外處理進行捕捉並根據情況進行錯誤回報或重試
	
	
	
*/


#include <iostream>
#include <stdexcept>

// 自定義例外類別
class DivisionByZeroException : public std::exception {
public:
    const char* what() const noexcept override {
        return "自定義錯誤: 除數不能為零!";
    }
};

// 函數：除法運算
double divide(double a, double b) {
    if (b == 0) {
        throw DivisionByZeroException();
    }
    return a / b;
}

int main() {
    double x = 10;
    double y = 0;

    try {
        std::cout << "結果: " << divide(x, y) << std::endl;
    }
    catch (const DivisionByZeroException& e) {
        std::cerr << "錯誤: " << e.what() << std::endl;
    }

    return 0;
}