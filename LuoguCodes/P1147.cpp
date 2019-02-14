//【P1147】连续自然数和 - 洛谷 - 0
#include <iostream>
int main() {
	int m, sum = 0, j;
	std::cin >> m;
	for (int i = 1; i <= m; ++i) {
		sum = 0;
		for (j = i; j < m; ++j)	{
			sum += j;
			if (sum >= m)
				break;
		}
		if (sum == m)
			std::cout << i << '; '; << j << std::endl;
	}			
}