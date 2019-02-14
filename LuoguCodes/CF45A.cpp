//【CF45A】Codecraft III - 洛谷 - Re
#include <string>
#include <iostream>

int main() {
	const std::string month[] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
	std::string input;
	std::cin >> input;
	int n;
	std::cin >> n;
	for (int i = 0; i < 12; ++i)
		if (input == month[i])
			std::cout << month[(i + n) % 12] << std::endl;
}