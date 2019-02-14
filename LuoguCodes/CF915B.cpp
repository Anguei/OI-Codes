//【CF915B】Browser - 洛谷 - Uk
#include <cmath>

#include <iostream> 
#include <algorithm>

int main() {
	int n, pos, l, r;
	std::cin >> n >> pos >> l >> r;
	if (l == 1 && r == n)
		std::cout << 0 << std::endl;
	else if (l == 1)
		std::cout << abs(pos - r) + 1 << std::endl;
	else if (r == n)
		std::cout << abs(pos - l) + 1 << std::endl;
	else
		std::cout << std::min(abs(pos - l) + 2 + r - l, abs(r - pos) + 2 + r - l) << std::endl;
}
