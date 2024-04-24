#ifndef THREESTACKS_H
#define THREESTACKS_H
#include <iostream>

class ThreeStacks {
public:
	ThreeStacks(const int size);
	~ThreeStacks();
	void push(const int idx, const int num);
	void pop(const int idx, const int num);
	int size(const int idx) const;
	int allSize() const;
	void print(const int idx1, const int idx2) const;
private:
	int* _data;
	int _size;
	int _countOfStacks;
	int _idx0;
	int _idx1;
	int _idx2;
	bool validSize(const int size) const;
	bool validIdx(const int idx) const;
	bool stackIsFull(const int idx) const;
	bool stackIsEmpty(const int idx) const;
};

struct StacksException {
	std::string s;
	friend std::ostream& operator<<(std::ostream& out, const StacksException& obj);
};
#endif
