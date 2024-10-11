// 引入輸入輸出流，用於打印訊息到控制台
#include <iostream>
// 引入標準限制，允許訪問數據類型的最大和最小值
#include <limits>
// 引入標準異常類，允許拋出和捕獲異常
#include <stdexcept>

int safe_add(int a, int b) {

	//std::numeric_limits<int>::max()       int 類型的最大值
	//std::overflow_error                   返回相應的錯誤訊息
	// std::numeric_limits<int>::min()      int 類型的最小值

	//整數類型及其範圍
	/*
	   int
          範圍：通常是 -2,147,483,648 到 2,147,483,647（即 -2^31 到 2^31 - 1）
          大小：4 字節
       short
           範圍：通常是 -32,768 到 32,767（即 -2^15 到 2^15 - 1）
           大小：2 字節
       long
         範圍：通常是 -2,147,483,648 到 2,147,483,647（與 int 相同），但在某些平台上可以更大（例如，long 在某些系統上是 8 字節）。
         大小：通常是 4 字節或 8 字節（根據平台）
      long long
        範圍：-9,223,372,036,854,775,808 到 9,223,372,036,854,775,807（即 -2^63 到 2^63 - 1）
        大小：8 字節

		無符號整數

     C++ 還支持無符號整數類型，這些類型的範圍從 0 開始到其對應的最大值：
	unsigned int
		範圍：0 到 4,294,967,295（即 2^32 - 1）
	unsigned short
		範圍：0 到 65,535（即 2^16 - 1）
	unsigned long
		範圍：0 到 4,294,967,295（通常）
	unsigned long long
		範圍：0 到 18,446,744,073,709,551,615（即 2^64 - 1）
	
	*/


	if (b > 0 && a > std::numeric_limits<int>::max() - b) {
		throw std::overflow_error("Integer overflow detected!");
	}
	else if (b < 0 && a < std::numeric_limits<int>::min() - b) {
		throw std::overflow_error("Integer underflow detected!");
	}
	return a + b;
}

int main() {
	try {
		int result = safe_add(2147483647, 1); // 這裡會引發溢位
		std::cout << "Result: " << result << std::endl;
	}
	catch (const std::overflow_error& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}


/*
溢位處理（overflow handling）
   1. 整數溢位檢測
   2. 浮點數溢位檢測
   3. 使用類型安全的數據結構
   4. 使用異常處理
*/