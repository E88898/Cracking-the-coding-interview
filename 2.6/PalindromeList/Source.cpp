#include <iostream>
#include <stack>

struct node {
	node* next;
	int val;
};

bool isPalidorme(node* head) {
	if (!head) {
		return false;
	}
	node* temp = head;
	std::stack<int> st;
	while (temp) {
		st.push(temp->val);
		temp = temp->next;
	}
	while (head) {
		int i = st.top();
		st.pop();
		if (head->val != i) {
			return false;
		}
		head = head->next;
	}
	return true;
}

int main(){

	return 0;
}