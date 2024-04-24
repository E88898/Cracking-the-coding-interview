#include <iostream>
#include <stack>
#include <vector>



// why throwed exception ????? all is good no ?

struct node {
	node(int x) : left{ nullptr }, right{ right }, value{ x } {};
	node* left;
	node* right;
	int value;
};

bool isBST(node* root) {
	std::stack<node*> s;
	std::vector<int> v;
	while (true) {
		if (root) {
			s.push(root);
			root = root->left;
		}
		else {
			v.push_back(s.top()->value);
			root = s.top()->right;
			s.pop();
			if (!s.size() && !root) {
				break;
			}
		}
	}
	for (int i = 0; i < v.size() - 1; ++i) {
		if (v[i] > v[i + 1]) {
			return false;
		}
	}
	return true;
}

int main() {

	node* root = new node(6);
	node* left = root;
	left->left = new node(4);
	left = left->left;
	left->left = new node(1);
	left->right = new node(5);
	node* right = root;
	right->right = new node(8);
	right = right->right;
	right->left = new node(7);
	right->right = new node(12);
	right = right->right;
	right->left = new node(11);

	if (isBST(root)) {
		std::cout << "BST";
	}
	else {
		std::cout << ".!.";
	}

	return 0;
}