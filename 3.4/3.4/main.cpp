#include "MyQueue.h"

int main() {

	MyQueue q(5);
	for (int i = 0; i < 5; ++i) {
		q.push(i);
	}
	for (int i = 0; i < 5; ++i) {
		q.print(i);
		std::cout << ' ';
	}

	q.pop();
	q.pop();
	std::cout << std::endl;
	for (int i = 0; i < q.size(); ++i) {
		q.print(i);
		std::cout << ' ';
	}
	return 0;
}