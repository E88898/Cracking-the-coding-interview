#ifndef MYQUEUE_H
#define MYQUEUE_H
#include <iostream>
#include <vector>

class MyQueue {
public:
	MyQueue(const int capacity);
	void push(const int num);
	void pop();
	int first() const;
	int end() const;
	void print(const int idx) const;
	int size() const;

private:
	std::vector<int> _data;
	int _capacity;
	int _index;
};

struct ExceptionMyQueue {
	std::string s;
};

#endif
