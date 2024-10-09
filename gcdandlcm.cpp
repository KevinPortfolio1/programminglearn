
#include <iostream>
using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int main()
{
	int num1, num2;
	cout << "請輸入兩個整數: ";
	cin >> num1 >> num2;

	int result = gcd(num1, num2);
	cout << "最大公因數是: " << result << endl;

	return 0;
}


/*
實際運用
   分數
   资源分配
   密碼學   生成 RSA 密鑰對
   圖形和設計
   信號處理  最小周期,信號的採樣频率
   编程算法
*/

/*
计算最小公倍数
int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
*/
