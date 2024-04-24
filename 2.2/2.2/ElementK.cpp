#include "ElementK.h"

ForwardList::ForwardList()
	: _header{ nullptr }
{
}

ForwardList::~ForwardList()
{
	while (_header != nullptr) {
		node* ptr = _header;
		_header = _header->_next;
		delete ptr;
	}
}

void ForwardList::push_front(const int number)
{
	if (_header == nullptr) {
		node* ptr = new node;
		ptr->_data = number;
		_header = ptr;
	}
	else {
		node* ptr = new node;
		ptr->_next = _header;
		ptr->_data = number;
		_header = ptr;
	}
}

void ForwardList::pop_front()
{
	if (_header == nullptr) {
		throw ListException{ "empty list" };
	}
	else {
		node* ptr = _header->_next;
		delete _header;
		_header = ptr;
	}
}

void ForwardList::push_back(const int number) {
	node* ptr = _header;
	while (true) {
		if (ptr->_next == nullptr) {
			break;
		}
		ptr = ptr->_next;
	}
	node* temp = new node;
	temp->_data = number;
	ptr->_next = temp;
}

void ForwardList::insert_after(node* const n, const int number)
{
	node* ptr = new node;
	ptr->_next = n->_next;
	ptr->_data = number;
	n->_next = ptr;
}

void ForwardList::remove_after(node* const n)
{
	if (n->_next = nullptr) {
		throw ListException{ "last node" };
	}
	else {
		node* ptr = n->_next;
		n->_next = ptr->_next;
		delete ptr;
	}

}

void ForwardList::elementK(const int index) const
{
	// n + n + n
	int left = 0;
	int right = size() - 1;
	int reverseIndex=0;
	while (left < right) {
		if (index == left) {
			reverseIndex = right;
		}
		if (index == right) {
			reverseIndex = left;
		}
		++left;
		--right;
	}
	std::cout << getNode(reverseIndex)->_data;
	

}

void ForwardList::print(const int index) const
{
	node* ptr = _header;
	for (int i = 0; i <= index; ++i) {
		if (ptr == nullptr) {
			throw ListException{ "index out of bounds" };
		}
		if (i == index) {
			break;
		}
		ptr = ptr->_next;
	}

	std::cout << ptr->_data;
}

int ForwardList::size() const
{
	int size = 0;
	node* ptr = _header;
	while (ptr != nullptr) {
		ptr = ptr->_next;
		++size;
	}
	return size;
}

node* ForwardList::getNode(const int index) const
{
	if (index >= size()) {
		throw ListException{ "index out of bounds" };
	}
	node* ptr = _header;
	for (int i = 0; i < index; ++i) {
		ptr = ptr->_next;
	}
	return ptr;
}


std::ostream& operator<<(std::ostream& out, const ListException& obj)
{
	out << obj.s;
	return out;
}
