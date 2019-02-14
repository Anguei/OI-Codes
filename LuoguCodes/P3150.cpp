//【P3150】pb的游戏（1） - 洛谷 - 0
#include <iostream>

#define ZS std::cout << "zs wins" << std::endl;
#define PB std::cout << "pb wins" << std::endl;

int main() {
	int n;
	std::cin >> n;
	while (n--) {
		int m;
		std::cin >> m;
		if (m % 2 == 0)	
			PB
		else
			ZS
	}
}