#include <iostream>

struct Node {
	int data;
	Node* left;
	Node* right;

	Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
	Node* root;

public:
	BinaryTree() : root(nullptr) {}

	// 插入新節點
	void insert(int val) {
		root = insertRec(root, val);
	}

	// 前序遍歷
	void preOrder() {
		preOrderRec(root);
		std::cout << std::endl;
	}

	// 中序遍歷
	void inOrder() {
		inOrderRec(root);
		std::cout << std::endl;
	}

	// 後序遍歷
	void postOrder() {
		postOrderRec(root);
		std::cout << std::endl;
	}

private:
	Node* insertRec(Node* node, int val) {
		if (node == nullptr) {
			return new Node(val);
		}
		if (val < node->data) {
			node->left = insertRec(node->left, val);
		}
		else {
			node->right = insertRec(node->right, val);
		}
		return node;
	}

	void preOrderRec(Node* node) {
		if (node != nullptr) {
			std::cout << node->data << " "; // 根
			preOrderRec(node->left);         // 左
			preOrderRec(node->right);        // 右
		}
	}

	void inOrderRec(Node* node) {
		if (node != nullptr) {
			inOrderRec(node->left);         // 左
			std::cout << node->data << " "; // 根
			inOrderRec(node->right);        // 右
		}
	}

	void postOrderRec(Node* node) {
		if (node != nullptr) {
			postOrderRec(node->left);       // 左
			postOrderRec(node->right);      // 右
			std::cout << node->data << " "; // 根
		}
	}
};

// 使用示例
int main() {
	BinaryTree tree;
	tree.insert(5);
	tree.insert(3);
	tree.insert(8);
	tree.insert(1);
	tree.insert(4);

	std::cout << "前序遍歷: ";
	tree.preOrder(); // 輸出: 5 3 1 4 8

	std::cout << "中序遍歷: ";
	tree.inOrder();  // 輸出: 1 3 4 5 8

	std::cout << "後序遍歷: ";
	tree.postOrder(); // 輸出: 1 4 3 8 5

	return 0;
}

/*
Output
前序遍歷: 5 3 1 4 8
中序遍歷: 1 3 4 5 8
後序遍歷: 1 4 3 8 5
*/