//【P2084】进制转换 - 洛谷 - 0
#include <iostream>
#include <cstdio> 
#include <string>

int main() {
	int m;
	std::cin >> m;
	std::string n;
	std::cin >> n;
	int ans = 0;
	printf("%d*%d^%d", n[0] - 48, m, n.size() - 1);
	for (int i = 1; i < n.size(); ++i) {
		if (n[i] - 48 != 0)
			printf("+%d*%d^%d", n[i] - 48, m, n.size() - i - 1);
	}
	std::cout << std::endl;
}