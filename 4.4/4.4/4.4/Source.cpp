#include <iostream>

struct node {
	node(int x) : left{ nullptr }, right{ nullptr }, val{ x } {};
	node* left;
	node* right;
	int val;
};

bool answer;

int height(node* root) {
	if (!root) {
		return 0;
	}
	if (!answer) {
		return 0;
	}
	int left = height(root->left);
	int right = height(root->right);
	if (std::abs(left - right) > 1) {
		answer = false;
	}
	return std::max(left, right) + 1;
}


bool isBalanced(node* root) {
	if (!root) {
		return false;
	}
	answer = true;
	int temp = height(root);
	return answer;
}

int main() {
	node* root = new node(1);
	node* left = root;
	left->left = new node(2);
	left = left->left;
	left->left = new node(3);
	left = left->left;
	left->left = new node(4);
	node* right = root;
	right->right = new node(2);
	right = right->right;
	right->right = new node(3);
	right = right->right;
	right->right = new node(4);

	/*
			1
		  /   \
		2	    2
	  /          \
	3	           3
  /	                \
4                     4

	*/

	if (isBalanced(root)) {
		std::cout << "balanced";
	}
	else {
		std::cout << ".!.";
	}
	return 0;
}