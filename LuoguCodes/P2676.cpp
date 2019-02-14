//【P2676】超级书架 - 洛谷 - 0
#include <iostream>
#include <algorithm>

int main() {
	int n, b;
	std::cin >> n >> b;
	int *h = new int[n];
	for (int i = 0; i < n; ++i) 
		std::cin >> h[i];
	std::sort(h, h + n, std::greater<int>());
	for (int i = 0; i < n; ++i) {
		if (std::accumulate(h, h + i, 0) >= b) {
			std::cout << i  << std::endl;
			return 0;
		}
	}
}