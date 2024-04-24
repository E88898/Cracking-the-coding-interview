#include "MyQueue.h"

MyQueue::MyQueue(const int capacity) 
	:_capacity{capacity},
	_index{0}
{

}

void MyQueue::push(const int num)
{
	if (_index == _capacity) {
		throw ExceptionMyQueue{ "full queue" };
	}
	_data.push_back(num);
	++_index;
}

void MyQueue::pop()
{
	if (_index == 0) {
		throw ExceptionMyQueue{ "empty queue" };
	}
	for (int i = 0; i < _index - 1; ++i) {
		_data[i] = _data[i + 1];
	}
	--_index;
}

int MyQueue::first() const
{
	return _data[0];
}

int MyQueue::end() const
{
	return _data[_index - 1];
}

void MyQueue::print(const int idx) const
{
	std::cout << _data[idx];

}

int MyQueue::size() const
{
	return _index;
}


