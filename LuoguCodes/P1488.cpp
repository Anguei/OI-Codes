//【P1488】肥猫的游戏 - 洛谷 - 90
#include <cmath>

#include <vector>
#include <iostream>
#include <algorithm>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> a(3);
	for (int i = 0; i < 3; ++i)
		std::cin >> a[i];
	std::sort(a.begin(), a.end());
	if (n % 2 == 0) {
		std::cout << "JMcat Win" << std::endl;
	} else {
		int count = 0;
		//if (static_cast<int>(
		//		static_cast<bool>(std::abs(a[0] - a[1]))
		//		+ static_cast<bool>(std::abs(a[0] - a[2]))
		//		+ static_cast<bool>(std::abs(a[1] - a[2]))
		//	) == 2 )
		if (std::abs(a[0] - a[1]) == 1)
			count += 1;
		if (std::abs(a[1] - a[2]) == 1)
			count += 1;
		if (std::abs(a[0] - a[2]) == 1)
			count += 1;
		if (count == 2) 
			std::cout << "JMcat Win" << std::endl;
		else
			std::cout << "PZ Win" << std::endl;
	}
}