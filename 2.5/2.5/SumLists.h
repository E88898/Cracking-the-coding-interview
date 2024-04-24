#ifndef SUMLISTS_H
#define SUMLISTS_H
#include <iostream>
#include <vector>
#include <cmath>

struct node {
	node() : _next{ nullptr }, _data{ 0 } {};
	node* _next;
	int _data;
};

class ForwardList {
public:
	ForwardList();
	ForwardList(node* n);
	~ForwardList();
	ForwardList(const ForwardList& obj);
	void push_front(const int number);
	void pop_front();
	void push_back(const int number);

	void insert_after(node* const n, const int number);
	void remove_after(node* const n);
	
	node* sumLists(node* heaad1, node* head2);
	void print(const int index) const;
	int size() const;
	node* getNode(const int index) const;
	node* head();

private:
	node* _header;
};

struct ListException {
	std::string s;
	friend std::ostream& operator<<(std::ostream& out, const ListException& obj);

};

#endif
