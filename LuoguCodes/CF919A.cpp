//【CF919A】Supermarket - 洛谷 - Wa
#include <iomanip>
#include <iostream>
#include <algorithm>

int main() {
	int n, m;
	std::cin >> m >> n;
	std::vector<long double> prices;
	for (int i = 1; i <= m; ++i) {
		int _a, _b;
		std::cin >> _a >> _b;
		prices.push_back(static_cast<long double>(_a) / _b);
	}
	std::sort(prices.begin(), prices.end());
	std::cout << std::fixed << std::setprecision(7) << prices.front() * n << std::endl;
}