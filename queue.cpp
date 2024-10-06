#include <iostream>
#include <queue>

//queue
//C++ 標準庫中提供的一種序列容器，主要用於實現佇列（Queue）數據結構
//先進先出（FIFO，First In First Out）的資料結構
//基本特性
//先進先出（FIFO）
//隨機訪問不受支持
//自動管理記憶體
//支持多種底層容器


int main() {
	std::queue<int> q;

	// 添加元素
	q.push(1);
	q.push(2);
	q.push(3);

	// 獲取佇列大小
	std::cout << "佇列大小: " << q.size() << std::endl; // 輸出 3

	// 訪問佇列前端元素
	std::cout << "前端元素: " << q.front() << std::endl; // 輸出 1

	// 刪除前端元素
	q.pop();
	std::cout << "刪除後前端元素: " << q.front() << std::endl; // 輸出 2

	// 列印所有元素
	std::cout << "佇列元素: ";
	while (!q.empty()) {
		std::cout << q.front() << " "; // 輸出 2 3
		q.pop();
	}
	std::cout << std::endl;

	return 0;
}

/*
Output
佇列大小: 3
前端元素: 1
刪除後前端元素: 2
佇列元素: 2 3
*/