#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int binarySearch(const vector<int>& arr, int target) {
	int left = 0;
	int right = arr.size() - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (arr[mid] == target) {
			return mid; 
		}
		if (arr[mid] < target) {
			left = mid + 1; 
		}
		else {
			right = mid - 1; 
		}
	}
	return -1; 
}

int main()
{
	vector<int> arr;
	arr = { 4, 2, 3, 1, 5 };
	int target = 3;
	auto start = chrono::high_resolution_clock::now(); 
	int result = binarySearch(arr, target);
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, milli> duration = end - start;

	// 輸出結果
	if (result != -1) {
		cout << "元素 " << target << " 的索引是: " << result << endl;
	}
	else {
		cout << "元素未找到" << endl;
	}

	cout << "執行時間: " << duration.count() << " 毫秒" << endl;
	cout << "所需記憶體: " << sizeof(arr) + arr.size() * sizeof(int) << " bytes" << endl;

	return 0;

}


/*
Output

元素 3 的索引是: 2
執行時間: 0.0008 毫秒
所需記憶體: 36 bytes

*/