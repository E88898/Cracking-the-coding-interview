#include <iostream>

struct node {
	node* next;
	int val;
};

node* intersection(node* head1, node* head2) {
	if (!head1 || !head2) {
		return nullptr;
	}
	node* ptr1 = head1;
	node* ptr2 = head2;
	int size1 = 1;
	while (ptr1->next != nullptr) {
		ptr1 = ptr1->next;
		++size1;
	}
	int size2 = 1;
	while (ptr2->next != nullptr) {
		ptr2 = ptr2->next;
		++size2;
	}
	if (ptr1 != ptr2) {
		return nullptr;
	}
	ptr1 = head1;
	ptr2 = head2;

	int diff;
	int i = 0;
	while (true) {
		if (size1 > size2) {
			diff = size1 - size2;
			ptr1 = ptr1->next;
		}
		else {
			diff = size2 - size1;
			ptr2 = ptr2->next;
		}
		++i;
		if (i == diff) {
			break;
		}
	}

	while (ptr1 != ptr2) {
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	return ptr1;
}