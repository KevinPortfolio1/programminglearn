#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <chrono>

using namespace std;
using namespace std::chrono;

// 泡沫排序
void bubbleSort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
}

// 快速排序
int partition(int arr[], int low, int high) {
	int pivot = arr[high], i = (low - 1);
	for (int j = low; j < high; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

// 合併排序
void merge(int arr[], int l, int m, int r) {
	int n1 = m - l + 1, n2 = r - m;
	vector<int> L(n1), R(n2);
	for (int i = 0; i < n1; i++) L[i] = arr[l + i];
	for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
	int i = 0, j = 0, k = l;
	while (i < n1 && j < n2) {
		arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
	}
	while (i < n1) arr[k++] = L[i++];
	while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

//template: 這是一個關鍵字，用於告訴編譯器這是一個模板定義
//<typename Func>: 這表示我們正在定義一個模板參數，這裡的 Func 是一個類型參數，可以是任何類型（通常是函式指針或函式對象）

// 計算執行時間的函式
template<typename Func>
void measureTime(Func func, int arr[], int n) {
	auto start = high_resolution_clock::now();
	func(arr, n);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "執行時間: " << duration.count() << " 微秒" << endl;
}


template<typename Func2>
void measureTime2(Func2 sortFunc, int arr[], int n) {
	auto start = high_resolution_clock::now();
	sortFunc(arr, 0, n - 1);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "執行時間: " << duration.count() << " 微秒" << endl;
}

int main()
{
	const int n = 10;
	int arr[n];

	// 生成隨機數字
	srand(time(0));
	for (int &num : arr) {
		num = rand() % 100;
	}

	// 顯示原始陣列
	cout << "原始陣列: ";
	for (int num : arr) cout << num << " ";
	cout << endl;

	// 泡沫排序
	int arrBubble[n];
	copy(arr, arr + n, arrBubble);
	cout << "泡沫排序: ";
	measureTime(bubbleSort, arrBubble, n);

	// 快速排序
	int arrQuick[n];
	copy(arr, arr + n, arrQuick);
	cout << "快速排序: ";
	measureTime2(quickSort, arrQuick, n );

	// 合併排序
	int arrMerge[n];
	copy(arr, arr + n, arrMerge);
	cout << "合併排序: ";
	measureTime2(mergeSort, arrMerge,  n);

	return 0;
}


/*

Output

原始陣列: 88 26 94 99 74 96 8 4 85 73
冒泡排序: 執行時間: 3 微秒
快速排序: 執行時間: 2 微秒
合併排序: 執行時間: 120 微秒

*/


/*

排序演算法	最壞情況時間複雜度	平均情況時間複雜度	最好情況時間複雜度	        執行時間特徵
泡沫排序	    O(n²)	                O(n²)	        O(n)	           效率較低，適合小數據集
快速排序	    O(n²)	            O(n log n)	      O(n log n)	       通常是最快的選擇，對大數據集有效
合併排序	   O(n log n)	        O(n log n)	      O(n log n)	       穩定，適合處理大型數據集



排序演算法	記憶體使用	    說明
冒泡排序	O(1)	       原地排序，常數空間使用
插入排序	O(1)	       原地排序，常數空間使用
選擇排序	O(1)	       原地排序，常數空間使用
快速排序	O(log n)~O(n)  遞迴深度影響空間需求
合併排序	O(n)	       需要額外的合併陣列
堆排序	    O(1)	       原地排序，常數空間使用


總結
	冒泡排序：適合小數據集，但對大數據集效率低下。
	快速排序：高效且常用，適合大多數情況。
	合併排序：穩定且效率高，適合大型數據集。

大數據的大小通常以 TB、PB甚至更高的量級（如 EB）來衡量。

*/