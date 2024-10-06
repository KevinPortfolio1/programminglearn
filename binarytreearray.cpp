#include <iostream>
#include <vector>

class BinaryTreeArray {
private:
	std::vector<int> tree;

public:
	BinaryTreeArray(int capacity) {
		tree.resize(capacity, -1); // 初始化樹，使用 -1 表示空節點
	}

	void insert(int index, int value) {
		if (index >= tree.size()) {
			std::cout << "索引超出範圍!" << std::endl;
			return;
		}
		tree[index] = value;
	}

	void printTree() {
		for (int value : tree) {
			if (value != -1) {
				std::cout << value << " ";
			}
		}
		std::cout << std::endl;
	}
};

// 使用示例
int main() {
	BinaryTreeArray tree(10); // 創建容量為 10 的二元樹

	tree.insert(0, 5); // 根節點
	tree.insert(1, 3); // 左子節點
	tree.insert(2, 8); // 右子節點
	tree.insert(3, 1); // 左左子節點
	tree.insert(4, 4); // 左右子節點

	std::cout << "樹的元素: ";
	tree.printTree(); // 輸出 5 3 8 1 4

	return 0;
}