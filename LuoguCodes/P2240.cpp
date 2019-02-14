//【P2240】数的计数数据加强版 - 洛谷 - 0
#include <iostream>

const int kMaxN = 1500000;
int f[kMaxN + 5] = {1, 1};

int main() {
	int n;
	std::cin >> n;
	for (int i = 2; i <= n; ++i)
		f[i] = f[i - 2] + f[i / 2];
	std::cout << f[n] << std::endl;
}