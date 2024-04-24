#include "SortedStack.h"

SortedStack::SortedStack(const int capacity)
	:_capacity{capacity}
{
}

void SortedStack::push(const int num)
{
	if (_data.size() == _capacity) {
		throw ExceptionStack{ "full stack" };
	}
	_data.push_back(num);
	sort(_data);
}

void SortedStack::pop()
{
	if (isEmpty()) {
		throw ExceptionStack{ "empty stack" };
	}
	_data.pop_back();
}

int SortedStack::peek() const
{
	return _data[_data.size() - 1];
}

int SortedStack::size() const 
{
	return _data.size();
}
bool SortedStack::isEmpty() const
{
	if (0 == _data.size()) {
		return true;
	}
	return false;
}

void SortedStack::print(const int idx) const
{
	std::cout << _data[idx];
}

void SortedStack::sort(std::vector<int>& data)
{
	for (int i = 0; i < _data.size(); ++i) {
		for (int j = i + 1; j < _data.size(); ++j) {
			if (_data[j] > _data[i]) {
				int temp = _data[i];
				_data[i] = _data[j];
				_data[j] = temp;

			}
		}
	}
}

std::ostream& operator<<(std::ostream& out, ExceptionStack& obj)
{
	out << obj.s;
	return out;
}
