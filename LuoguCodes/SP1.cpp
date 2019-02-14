//【SP1】TEST - Life, the Universe, and Everything - 洛谷 - Uk 
#include <iostream>

int main() {
	int a;
input:
	std::cin >> a;
	if (a != 42) {
		std::cout << a << std::endl;
		goto input;
	}
	return 0;
}