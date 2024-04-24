#include "SetOfStacks.h"

int main()
{
	SetOfStacks s;
	for (int i = 0; i < 33; ++i) {
		s.push(i);
	}
	for (int i = 0; i < 33; ++i) {
		s.print(i);
		std::cout << ' ';
	}

}