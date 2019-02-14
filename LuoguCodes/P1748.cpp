//【P1748】H 数 - 洛谷 - 94
#include <iostream>

int main() {
	long long h[10000 + 5];
	h[1] = 1;
	int i2, i3, i5, i7;
	i2 = i3 = i5 = i7 = 1;
	for (int i = 2; i <= 10000; ++i) {
		h[i] = h[i2] * 2;
		if (h[i] > h[i3] * 3)
			h[i] = h[i3] * 3;
		if (h[i] > h[i5] * 5)
			h[i] = h[i5] * 5;
		if (h[i] > h[i7] * 7)
			h[i] = h[i7] * 7;
		if (h[i] == h[i2] * 2)
			++i2;
		if (h[i] == h[i3] * 3)
			++i3;
		if (h[i] == h[i5] * 5)
			++i5;
		if (h[i] == h[i7] * 7)
			++i7;
	}
	int n;
	while (std::cin >> n)
		std::cout << h[n] << std::endl;
}