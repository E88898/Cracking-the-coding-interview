#include "ThreeStacks.h"

ThreeStacks::ThreeStacks(const int size)
	:_data{nullptr},
	_size{1},
	_countOfStacks{3},
	_idx0{0},
	_idx1{0},
	_idx2{0}
{
	if(!validSize(size)) {
		throw StacksException{ "size < 1" };
	}
	_size = size;
	_data = new int[_size * _countOfStacks];
	_idx1 = _size * _countOfStacks / 3;
	_idx2 = 2 * _size * _countOfStacks / 3;
}

ThreeStacks::~ThreeStacks()
{
	delete[] _data;
}

void ThreeStacks::push(const int idx, const int num)
{
	if (!validIdx(idx)) {
		throw StacksException{ "idx out of bounds" };
	}
	if (stackIsFull(idx)) {
		throw StacksException{ "full stack" };
	}
	if (0 == idx) {
		_data[_idx0] = num;
		++_idx0;
	}
	if (1 == idx) {
		_data[_idx1] = num;
		++_idx1;
	}
	if (2 == idx) {
		_data[_idx2] = num;
		++_idx2;
	}
}

void ThreeStacks::pop(const int idx, const int num)
{
	if (!validIdx(idx)) {
		throw StacksException{ "index out of bounds" };
	}
	if (stackIsFull(idx)) {
		throw StacksException{ "empyt stack" };
	}
	if (1 == idx) {
		--_idx0;
	}
	if (2 == idx) {
		--_idx1;
	}
	if (3 == idx) {
		--_idx2;
	}

}

int ThreeStacks::size(const int idx) const
{	
	if (!validIdx(idx)) {
		throw StacksException{ "index out of bounds" };
	}

	if (0 == idx) {
		return _idx0;
	}
	if (1 == idx) {
		return _idx1;
	}
	if (2 == idx) {
		return _idx2;
	}
	return 0;
	
}

int ThreeStacks::allSize() const
{
	return  _countOfStacks;
}

void ThreeStacks::print(const int idx1, const int idx2) const
{
	if (!validIdx(idx1)) {
		throw StacksException{ "index out of bounds" };
	}
	if (0== idx1 && (idx2 >=0 && idx2 < _idx0)) {
		std::cout << _data[idx2];
	}
	if (1 == idx1 && (idx2 >= 0 && idx2 < _idx1 - ((_size * _countOfStacks) / 3))) {
		std::cout << _data[idx2 + ((_size * _countOfStacks) / 3)];
	}
	if (2 == idx1 && (idx2 >= 0 && idx2 < _idx2 - (( 2 * _size * _countOfStacks) / 3))) {
		std::cout << _data[idx2 + ((2 * _size * _countOfStacks) / 3)];
	}
	
}

bool ThreeStacks::validSize(const int size) const
{
	if (size > 0) {
		return true;
	}
	return false;
}

bool ThreeStacks::validIdx(const int idx) const
{
	if (idx >= 0 || idx <= 2) {
		return true;
	}
	return false;
}

bool ThreeStacks::stackIsFull(const int idx) const
{
	if (0 == idx && (_size * _countOfStacks) / 3 == _idx0) {
		return true;
	}
	if (1 == idx && (2 * _size * _countOfStacks) / 3 == _idx1) {
		return true;
	}
	if (2 == idx && _size == _idx2) {
		return true;
	}
	return false;
	
}

bool ThreeStacks::stackIsEmpty(const int idx) const
{
	if (0 == idx && 0 == _idx0) {
		return true;
	}
	if (1 == idx && (_size / 3) == _idx1) {
		return true;
	}
	if (2 == idx && (2 * _size * _countOfStacks) / 3 == _idx2) {
		return true;
	}
	return false;

}

std::ostream& operator<<(std::ostream& out, const StacksException& obj)
{
	out << obj.s;
	return out;
}
