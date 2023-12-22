#include "LRU.hpp"

int main() {
	LRU<int, int> c(4);

	c.refer(1, 1);
	c.refer(2, 2);
	c.refer(3, 3);
	c.refer(1, 1);
	c.refer(4, 4);
	c.refer(5, 5);
	c.display();
}