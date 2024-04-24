#ifndef SORTEDSTACK_H
#define SORTEDSTACK_H
#include <iostream>
#include <vector>

class SortedStack {
public:
	SortedStack(const int capacity);
	void push(const int num);
	void pop();
	int peek() const;
	int size() const;
	bool isEmpty() const;
	void print(const int idx) const;

private:
	std::vector<int> _data;
	int _capacity;
	void sort(std::vector<int>& data);
};

struct  ExceptionStack {
	std::string s;
	friend std::ostream& operator<<(std::ostream& out, ExceptionStack& obj);
};
#endif
