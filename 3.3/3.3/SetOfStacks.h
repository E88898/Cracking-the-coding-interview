#ifndef SETOFSTACKS_H
#define SETOFSTACKS_H

#include <iostream>

class SetOfStacks {
public:
	SetOfStacks();
	SetOfStacks(const int num);
	~SetOfStacks();
	void push(const int num);
	void pop();
	int size() const;
	void print(const int idx) const;
private:
	int* _data;
	int _capacity;
	const int _treshold;
	int _index;
	bool treshold(const int idx) const;
	bool isEmpty(const int idx) const;
	bool isOver(const int idx) const;
	bool validIndex(const int idx) const;
};

struct ExceptionStacks {
	std::string s;
	friend std::ostream& operator<<(std::ostream& out, ExceptionStacks& obj);
};

#endif
