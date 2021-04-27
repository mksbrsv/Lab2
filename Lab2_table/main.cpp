#include "table.h"
#include <iostream>
#include "console_table.h"
int main() {
	sort_table<int, int> a;
	a.insert(5, 1);
	a.insert(2, 2);
	a.insert(3, 3);
	a.insert(4, 4);
	a.insert(7, 5);
	a.insert(9, 6);
	a.insert(8, 7);
	a.insert(10, 8);
	a.insertion();
	for(auto it = a.begin(); it != a.end(); ++it) {
		std::cout << it->key() << " " << it->value() << std::endl;
	}
	
}
