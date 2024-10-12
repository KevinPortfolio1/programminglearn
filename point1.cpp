

#include <iostream>
#include <memory>
using namespace std;


struct Point {
	int x;
	int y;
};

void move(Point* p, int dx, int dy) {
	p->x += dx; // 使用指標修改結構體的成員
	p->y += dy;
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp; // 交換兩個變量的值
}

int main()
{
	int var = 10;         // 宣告一個整數變量
	int* ptr = &var;     // ptr 是指向 var 的指標

	cout << "變量的值: " << var << endl;         // 輸出變量的值
	cout << "指標的值: " << ptr << endl;        // 輸出指標的值（地址）
	cout << "指標指向的值: " << *ptr << endl;  // 輸出指標指向的值

	/*
	Output
	 變量的值: 10
     指標的值: 010FF978
     指標指向的值: 10
	
	*/

	int arr1[] = { 1, 2, 3, 4, 5 }; // 宣告一個整數數組
	int* ptr1 = arr1;              // ptr 指向數組的第一個元素

	for (int i = 0; i < 5; ++i) {
		cout << "arr1[" << i << "] = " << *(ptr1 + i) << endl; // 使用指標遍歷數組
	}

	/*
	Output
	  arr1[0] = 1
      arr1[1] = 2
      arr1[2] = 3
      arr1[3] = 4
      arr1[4] = 5
	*/

	int* arr2 = new int[5]; // 動態分配一個整數數組

	for (int i = 0; i < 5; ++i) {
		arr2[i] = i + 1; // 初始化數組
	}

	for (int i = 0; i < 5; ++i) {
		cout << arr2[i] << " "; // 輸出數組
	}
	cout << endl;

	delete[] arr2; // 釋放記憶體

	//Output : 1 2 3 4 5

	Point pt = { 0, 0 };
	move(&pt, 5, 3); // 傳遞結構體的地址
	cout << "新位置: (" << pt.x << ", " << pt.y << ")" << endl;

	//Output :  新位置: (5, 3)

	int x = 10, y = 20;
	cout << "交換前: x = " << x << ", y = " << y << endl;
	swap(&x, &y); // 傳遞變量的地址
	cout << "交換後: x = " << x << ", y = " << y << endl;

	/*
	Output
	交換前: x = 10, y = 20
    交換後: x = 20, y = 10
	*/

	const char* names[] = { "Alice", "Bob", "Charlie" };

	for (int i = 0; i < 3; ++i) {
		cout << names[i] << endl; // 輸出字串陣列
	}
	/*
	  Output
	   Alice
       Bob
       Charlie
	*/

	unique_ptr<int> ptrauto = make_unique<int>(5); // 使用智能指標
	cout << "值: " << *ptrauto << endl; // 輸出智能指標的值

	/*
	 Output
	   值: 5
	*/

	return 0;
}


