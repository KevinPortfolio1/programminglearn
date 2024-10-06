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

	// 中序遍歷
	void inOrder() {
		inOrderRec(root);
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

	void inOrderRec(Node* node) {
		if (node != nullptr) {
			inOrderRec(node->left);
			std::cout << node->data << " ";
			inOrderRec(node->right);
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

	std::cout << "中序遍歷: ";
	tree.inOrder(); // 輸出 1 3 4 5 8

	return 0;
}