#include <iostream>
#include <list>
#include <queue>

struct node {
	node(int x) : left{ nullptr }, right{ nullptr }, value{ x } {};
	node* left;
	node* right;
	int value;
};

std::list<std::list<node*>> ListOfDepts(node* root) {
	std::list<std::list<node*>> ll;
	if (root) {
		std::list<node*> l;

		std::queue<node*> q;
		q.push(root);
		q.push(nullptr);
		while (q.size() != 1) {
			if (q.front()->left) {
				q.push(q.front()->left);
			}
			if (q.front()->right) {
				q.push(q.front()->right);
			}
			l.push_back(q.front());
			q.pop();
			if (q.front() == nullptr) {
				q.pop();
				ll.push_back(l);
				while (!l.empty()) {
					l.pop_back();
				}
				q.push(nullptr);
			}
		}
	}
	return ll;
}

int main() {
	node* root = new node(1);
	node* left = root;
	left->left = new node{ 2 };
	left = left->left;
	left->right = new node{ 3 };
	left->left = new node{ 3 };
	left = left->left;
	left->right = new node{ 4 };
	left->left = new node{ 4 };
	node* right = root;
	right->right = new node{ 2 };


	/*
						1
					  /   \
                    2       2
                  /  \
			     3    3
			   /  \
		     4     4
	*/

	std::list<std::list<node*>> l = ListOfDepts(root);
	while (!l.empty()) {
		while (!l.front().empty()) {
			std::cout << l.front().front()->value << ' ';
			l.front().pop_front();
		}
		std::cout << std::endl;
		l.pop_front();
	}

	return 0;
}