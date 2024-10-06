#include <iostream>
#include <vector>
#include <stdexcept>


//vector
// C++ 標準庫中提供的一種序列容器，主要用於存儲一組相同類型的元素。它是動態大小的陣列
//基本特性
//動態大小
//隨機訪問
//自動管理記憶體
//支援多種操作
//與 STL 兼容

class Stack {
private:
	std::vector<int> items;

public:
	void push(int item) {
		items.push_back(item);
	}

	void pop() {
		if (items.empty()) {
			throw std::out_of_range("pop from empty stack");
		}
		items.pop_back();
	}

	int top() {
		if (items.empty()) {
			throw std::out_of_range("peek from empty stack");
		}
		return items.back();
	}

	bool isEmpty() {
		return items.empty();
	}

	size_t size() {
		return items.size();
	}
};


int main()
{
	Stack stack;
	stack.push(1);
	stack.push(2);
	std::cout << stack.top() << std::endl;  // 輸出 2
	stack.pop();
	std::cout << stack.top() << std::endl;  // 輸出 1
	std::cout << stack.size() << std::endl; // 輸出 1
	return 0;
}

/*
Output

2
1
1

*/