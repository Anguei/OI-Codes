//【P1007】独木桥 - 洛谷 - 0 
#include <iostream> 

int main() {
	int l, n;
	std::cin >> l >> n;
	int *pos = new int[n + 1];
	for (int i = 1; i <= n; ++i)
		std::cin >> pos[i];
	int max = 0, min = 0;
	for (int i = 1; i <= n; ++i)
		max = std::max(max, std::max(l - pos[i] + 1, pos[i])),
		min = std::max(min, std::min(l - pos[i] + 1, pos[i]));
	std::cout << min << " " << max << std::endl;
}