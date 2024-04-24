#include "SumLists.h"

int main() {

	ForwardList l1;
	l1.push_front(1);
	l1.push_front(4);
	l1.push_front(6);

	ForwardList l2;
	l2.push_front(8);
	l2.push_front(0);
	l2.push_front(2);

	ForwardList l3(l1.sumLists(l1.head(), l2.head()));
	
	for (int i = 0; i < l3.size(); ++i) {
		l3.print(i);
		std::cout << ' ';
	}


	return 0;
}