#include <iostream>

struct node {
	node* _next;
	int _data;
};

node* loopDetection(node* head1) {
	node* slow = head1;
	node* fast = head1;
	
	while (fast && fast->next) {
		slow = slow->_next;
		fast = fast->_next->_next;
		if (slow == fast) {
			break;
		}
	}

	if (fast == nullptr || fast->_next == nullptr) {
		return nullptr;
	}

	slow = head1;
	while (slow != fast) {
		slow = slow->_next;
		fast = fast->_next;
	}
	return fast;
}

int main() {

	return 0;
}