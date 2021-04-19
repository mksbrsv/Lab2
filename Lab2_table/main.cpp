#include "table.h"
#include <iostream>
int main() {
	table<int, int> a;
	for(int i = 0; i < 10; i++) {
		a.push_back(5);
	}
	for (auto it = a.begin(); it != a.end(); ++it) {
		std::cout << it->value() << std::endl;
	}
}
