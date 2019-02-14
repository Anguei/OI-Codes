//【CF922A】Cloning Toys - 洛谷 - Uk 
#include <iostream>

const char *yes = "Yes", *no = "No";

int main() {
	int x, y;
	std::cin >> x >> y;
	if (y == 0)
		std::cout << no << std::endl;
	else if (x + 1 == y)
		std::cout << yes << std::endl;
	else if (x + y < y)
		std::cout << no << std::endl;
	else if (x + 1 > y && (x - y + 1) % 2 == 0 && y != 1)
		std::cout << yes << std::endl;
	else
		std::cout << no << std::endl;
}