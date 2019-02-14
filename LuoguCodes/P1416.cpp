//【P1416】攻击火星 - 洛谷 - 0 
#include <iostream> 

int main() {
	int n;
	std::cin >> n;
	if (n < 2) std::cout << 0 << std::endl;
	else std::cout << n - 2 << std::endl;
}