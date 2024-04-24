#include "SetOfStacks.h"

SetOfStacks::SetOfStacks()
	:_data{ nullptr },
	_capacity{ 10 },
	_treshold{_capacity},
	_index{0}

{
	_data = new int[_capacity];
}

SetOfStacks::SetOfStacks(const int num)
	:_data{ nullptr },
	_capacity{ 10 },
	_treshold{_capacity},
	_index{0}
{
	_data = new int[_capacity];
	_data[_index] = num;
	++_index;
}

SetOfStacks::~SetOfStacks()
{
	delete[] _data;
}

void SetOfStacks::push(const int num)
{
	if (!treshold(_index)) {
		_data[_index] = num;
	}
	else {
		int* temp = new int[_capacity + _treshold];
		for (int i = 0; i < _capacity; ++i) {
			temp[i] = _data[i];
		}
		delete[] _data;
		_data = temp;
		_data[_index] = num;
		_capacity += _treshold;
	}
	++_index;
}

void SetOfStacks::pop()
{
	if (!isEmpty(_index)) {
		throw ExceptionStacks{ "empty stack" };
	}
	else if (isOver(_index)) {
		int* temp = new int[_capacity - _treshold];
		_capacity -= _treshold;
		for (int i = 0; i < _capacity; ++i) {
			temp[i] = _data[i];
		}
		delete[] _data;
		_data = temp;
	}
	--_index;
}

int SetOfStacks::size() const
{
	return _index;
}

void SetOfStacks::print(const int idx) const
{
	if (!validIndex(idx)) {
		throw ExceptionStacks{ "index out of bounds" };
	}
	if (idx % 10 == 0 && idx > 0) {
		std::cout << std::endl << "started new stack" << std::endl;
	}
	std::cout << _data[idx];
}

bool SetOfStacks::treshold(const int idx) const
{
	if (idx == _capacity) {
		return true;
	}
	return false;
}

bool SetOfStacks::isEmpty(const int idx) const
{
	if (0 == _index) {
		return true;
	}
	return false;
}

bool SetOfStacks::isOver(const int idx) const
{
	if (_capacity - _treshold  + 1 == _index) {
		return true;
	}
	return false;
}

bool SetOfStacks::validIndex(const int idx) const
{
	if (idx > 0 && idx < _index) {
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& out, ExceptionStacks& obj)
{
	out << obj.s;
	return out;
}
