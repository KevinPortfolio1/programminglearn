#include <iostream>
#include <vector>
#include <limits>
#include <chrono>

using namespace std;
using namespace std::chrono;

pair<int, int> findMaxMin(const vector<int>& nums) {
	int maxVal = numeric_limits<int>::min(); // 初始化最大值
	int minVal = numeric_limits<int>::max(); // 初始化最小值

	for (int num : nums) {
		if (num > maxVal) {
			maxVal = num;
		}
		if (num < minVal) {
			minVal = num;
		}
	}

	return { maxVal, minVal };
}

int main() {
	vector<int> nums = { 3, 5, 1, 8, 2, -4, 7 };

	// c++ 17
	//auto[maxVal, minVal] = findMaxMin(nums);

	// 計算執行時間
	auto start = high_resolution_clock::now(); // 開始計時

	// c++ 11
	pair<int, int> result = findMaxMin(nums);

	auto end = high_resolution_clock::now(); // 結束計時
	auto duration = duration_cast<microseconds>(end - start); // 計算執行時間


	cout << "Max: " << result.first << ", Min: " << result.second << endl; // 輸出: Max: 8, Min: -4
	cout << "Execution time: " << duration.count() << " microseconds" << endl; // 輸出執行時間


	return 0;
}

/*
Output
Max: 8, Min: -4
Execution time: 1 microseconds

*/


/*

C++11

	自動類型推導：使用 auto 關鍵字。
	範圍 for 迴圈：簡化迴圈寫法。
	智慧指標：std::unique_ptr 和 std::shared_ptr。
	lambda 表達式：允許在需要函數的地方使用匿名函數。
	nullptr：用於空指標的更好選擇。
	標準庫增強：如 std::chrono、std::thread。

C++14

	改進的泛型 lambda：允許 lambda 使用 auto 類型推導。
	二進位字面值：可以使用 0b 前綴來表示二進位數。
	更好的範圍 for 迴圈：允許使用 begin() 和 end()。
	std::make_unique：輔助函數來創建 std::unique_ptr。

C++17

	結構化綁定：允許直接解構 pair 和 tuple。
	std::optional：表示可能缺失的值。
	std::variant：類似於聯合體，可以存儲不同類型的值。
	std::any：可以存儲任意類型的值。
	新標準庫函數：如 std::clamp。

C++20

	概念（Concepts）：用於強制型別約束。
	範圍（Ranges）：增強的 STL 算法。
	協程（Coroutines）：原生支持異步編程。
	std::format：提供格式化輸出的功能。
	三維向量支持：直接支持數學向量運算。


C++11

	發布年份：2011
	普遍使用率：C++11 是大多數現代 C++ 項目的基礎，幾乎所有的編譯器和標準庫都已支持 C++11 的特性。
	特性：自動類型推導、範圍 for 迴圈、智慧指標、lambda 表達式等，這些特性使得 C++ 開發變得更為簡潔和高效。

C++14

	發布年份：2014
	普遍使用率：C++14 的使用率相對於 C++11 要低一些，因為大多數開發者在轉向 C++17 時會跳過 C++14 的特性。
	特性：增強的泛型 lambda、二進位字面值、std::make_unique 等。這些特性雖然有用，但對於許多項目而言，C++11 的變革已經足夠。

C++17

	發布年份：2017
	普遍使用率：C++17 的使用率正在逐漸增長，許多新項目已經選擇使用 C++17。
	特性：結構化綁定、std::optional、std::variant 等。這些特性使得代碼更加靈活和易於維護。

C++20

	發布年份：2020
	普遍使用率：C++20 的普遍使用率還在增長中，許多編譯器已經開始支持其特性，但仍需時間讓開發者廣泛採用。
	特性：概念、範圍、協程等。這些特性大大增強了 C++ 的表達能力和性能。

使用情況總結

	C++11：幾乎所有現代 C++ 項目均基於此版本。
	C++14：使用率較低，多用於 C++11 的增強。
	C++17：逐漸被廣泛使用，特別是在新項目中。
	C++20：正在增長，但許多項目仍在考慮穩定性和兼容性，可能需要時間進一步普及。


*/