//【UVA100】The 3n + 1 problem - 洛谷 - Uke
#include <iostream>
#include <algorithm>

unsigned compute(unsigned x) {
	unsigned step = 0;
	while (x != 1) {
		++step;
		if (x % 2 == 1)
			x = 3 * x + 1;
		else 
			x /= 2;
	}
	return ++step;		
}

int main() {
	unsigned l, r;
	while (std::cin >> l >> r) {
		unsigned ans = 0;
		for (unsigned i = l; i <= r; ++i)
			ans = std::max(ans, compute(i));
		std::cout << l << " " << r << " " << ans << std::endl;
	}
}