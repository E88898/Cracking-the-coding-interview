#include <iostream>

struct node {
	node* next;
	int val;
};

node* reverseList(node* head) {
	if (!head) {
		return head;
	}
	node* curr = head;
	node* next = nullptr;
	node* prev = nullptr;
	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	head = prev;
	return head;
}
int main() {


}