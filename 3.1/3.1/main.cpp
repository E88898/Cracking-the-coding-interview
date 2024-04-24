#include "ThreeStacks.h"

int main() {

	ThreeStacks a(3);
	a.push(0, 2);
	a.push(0, 3);
	a.push(0, 4);
	try {
		a.push(0, 5);
	}
	catch (StacksException& e) {
		std::cout << e << std::endl;
	}

	a.push(1, 6);
	a.push(1, 7);
	a.push(1, 8);

	a.push(2, 10);
	a.push(2, 11);



	for (int i = 0; i < a.allSize(); ++i) {
		for (int j = 0; j < a.size(i); ++j) {
			a.print(i, j);
			std::cout << ' ';
		}
		std::cout << std::endl;
		
	}
	

	return 0;
}