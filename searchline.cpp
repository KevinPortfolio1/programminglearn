//iostream
//用於處理輸入和輸出操作
//vector
//用於存儲動態大小的數據集合
//chrono
//C++11 標準中引入的一個標頭檔，用於處理時間和時間間隔
//using namespace
//簡化對於命名空間（namespace）中成員的訪問
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;


//const 關鍵字用於指定變量、指標、參數或函式返回值為常量，表示這些內容的值在其生命週期內不能被修改
//& arr  直接引用原始的 vector<int> 對象
int linearSearch(const vector<int>& arr, int target) {
	for (int i = 0; i < arr.size(); ++i) {
		if (arr[i] == target) {
			return i; 
		}
	}
	return -1; 
}

int main()
{
	vector<int> arr = { 4, 2, 3, 1, 5 };
	// 開始計時
	auto start = chrono::high_resolution_clock::now();
	int result = linearSearch(arr, 3);
	// 結束計時
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;

	cout << "arr 查詢的位置:" << result << endl; 


	// 計算所需記憶體
	size_t memoryUsed = sizeof(int) * arr.size(); // 整數陣列的記憶體
	cout << "執行時間: " << duration.count() << " 毫秒" << endl;
	cout << "所需記憶體: " << memoryUsed / 1024 << " KB" << endl;

	//int result2 = linearSearch(arr, 0);
	//cout << result2 << endl;
	return 0;
}

// input
// vector<int> arr = { 4, 2, 3, 1, 5 }
// int result = linearSearch(arr, 3);
// output
// 2
// int result = linearSearch(arr, 0);
// -1


//加上記憶體和時間顯示
/*
arr 查詢的位置:2
執行時間: 0.0015 毫秒
所需記憶體: 0 KB

*/