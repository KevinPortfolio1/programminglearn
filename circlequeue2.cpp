#include <iostream>
#include <stdexcept>

class CircularQueue {
private:
	int* arr;           // 儲存佇列元素的動態陣列
	int front;          // 前端指標
	int rear;           // 後端指標
	int capacity;       // 佇列容量

public:
	// 構造函數
	CircularQueue(int size) {
		arr = new int[size];
		capacity = size;
		front = rear = 0;
	}

	// 析構函數
	~CircularQueue() {
		delete[] arr;
	}

	// 入佇列
	void enqueue(int item) {
		if ((rear + 1) % capacity == front) { // 檢查是否已滿
			throw std::out_of_range("佇列已滿!");
		}
		arr[rear] = item;
		rear = (rear + 1) % capacity; // 環狀更新後端指標
	}

	// 出佇列
	void dequeue() {
		if (front == rear) { // 檢查是否為空
			throw std::out_of_range("佇列為空!");
		}
		front = (front + 1) % capacity; // 環狀更新前端指標
	}

	// 獲取前端元素
	int frontElement() {
		if (front == rear) { // 檢查是否為空
			throw std::out_of_range("佇列為空!");
		}
		return arr[front];
	}

	// 檢查佇列是否為空
	bool isEmpty() {
		return front == rear;
	}

	// 獲取佇列大小
	int size() {
		return (rear - front + capacity) % capacity;
	}
};

// 使用示例
int main() {
	CircularQueue q(5); // 創建容量為 5 的環狀佇列

	// 入佇列
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);

	std::cout << "佇列大小: " << q.size() << std::endl; // 輸出 3
	std::cout << "前端元素: " << q.frontElement() << std::endl; // 輸出 1

	// 出佇列
	q.dequeue();
	std::cout << "刪除後前端元素: " << q.frontElement() << std::endl; // 輸出 2

	// 繼續入佇列
	q.enqueue(4);
	q.enqueue(5);

	// 嘗試再次入佇列，會引發異常
	try {
		q.enqueue(6); // 佇列已滿
	}
	catch (const std::out_of_range& e) {
		std::cerr << e.what() << std::endl;
	}

	// 列印佇列中的所有元素
	std::cout << "佇列中的元素: ";
	while (!q.isEmpty()) {
		std::cout << q.frontElement() << " "; // 輸出 2 3 4 5
		q.dequeue();
	}
	std::cout << std::endl;

	return 0;
}