//【P1887】乘积最大3 - 洛谷 - 0 
#include <iostream> 

int main() {
	int n, m;
	std::cin >> n >> m;
	for (int i = 0; i < m - (n - (n / m) * m); ++i)
		std::cout << n / m << " ";
	for (int i = 0; i < n - (n / m) * m; ++i)
		std::cout << n / m + 1 << " ";
	std::cout << std::endl;
}