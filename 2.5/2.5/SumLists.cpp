#include "SumLists.h"

ForwardList::ForwardList()
	: _header{ nullptr }
{
}

ForwardList::ForwardList(node* n)
	:_header{ n }
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

node* ForwardList::sumLists(node* head1, node* head2)
{
	int carry = 0;
	node* ptr = nullptr;
	node* temp = ptr;
	while (head1 != nullptr || head2 != nullptr) {
		int dig1 = (head1 == nullptr ? 0 : head1->_data);
		int dig2 = (head2 == nullptr ? 0 : head2->_data);
		int dig = (dig1 + dig2 + carry) % 10;
		carry = (dig1 + dig2) / 10;
		node* t = new node;
		t->_data = dig;
		if (!ptr) {
			ptr = t;
			temp = t;
		}
		else {
			temp->_next = t;
			temp = temp->_next;
		}
		if (head1) {
			head1 = head1->_next;
		}
		if (head2) {
			head2 = head2->_next;
		}
	}
	if (carry) {
		temp ->_next = new node;
		temp->_next->_data = carry;
	}
	return ptr;
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

node* ForwardList::head()
{
	return _header;
}


std::ostream& operator<<(std::ostream& out, const ListException& obj)
{
	out << obj.s;
	return out;
}
