//【CF939A】Love Triangle - 洛谷 - Uk
#include <vector>
#include <iostream>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> f(n + 1);
	for (int i = 1; i <= n; ++i)
		std::cin >> f[i];
	for (int i = 1; i <= n; ++i) {
		int a = i;
		int b = f[a];
		int c = f[b];
		if (f[c] == a) {
			std::cout << "YES" << std::endl;
			return 0;
		}
	}
	std::cout << "NO" << std::endl;
}