#include "RemoveDups.h"

int main() {

	ForwardList l;
	l.push_front(1);
	l.push_front(2);
	l.push_front(4);
	l.push_front(4);
	l.push_front(6);

	for (int i = 0; i < l.size(); ++i) {
		l.print(i);
		std::cout << ' ';
	}

	std::cout << std::endl;
	l.remove_dups();
	for (int i = 0; i < l.size(); ++i) {
		l.print(i);
		std::cout << ' ';
	}

	

	return 0;
}