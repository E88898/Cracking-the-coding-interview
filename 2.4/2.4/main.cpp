#include "Partition.h"

int main() {

	ForwardList l;
	l.push_front(1);
	l.push_front(2);
	l.push_front(10);
	l.push_front(5);
	l.push_front(8);
	l.push_front(5);
	l.push_front(3);
	for (int i = 0; i < l.size(); ++i) {
		l.print(i);
		std::cout << ' ';
	}

	std::cout << std::endl;
	l.partiton(l.getNode(3));
	for (int i = 0; i < l.size(); ++i) {
		l.print(i);
		std::cout << ' ';
	}

	return 0;
}