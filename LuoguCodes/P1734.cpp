//【P1734】最大约数和 - 洛谷 - 0 
#include <iostream>
#include <algorithm>

const int kMaxS = 1000; 

int ysh[kMaxS + 5] = { 0 }, f[kMaxS] = { 0 };

inline void init() { for (register int i = 1; i <= kMaxS; ++i) { for (register int j = 1; j * j <= i; ++j) { if (i % j == 0) { ysh[i] += j; if (j * j != i) ysh[i] += (i / j); } } ysh[i] -= i; } }

int main() {
	int s;
	std::cin >> s;
	init();
	//for (register int i = 1; i <= s; ++i) std::cout << i << " " << ysh[i] << std::endl;
	for (register int i = 2; i <= s; ++i) for (register int j = s; j >= i; --j) f[j] = std::max(f[j], f[j - i] + ysh[i]);
	std::cout << f[s] << std::endl;
}