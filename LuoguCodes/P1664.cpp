//【P1664】每日打卡心情好 - 洛谷 - 60
#include <cmath> 
#include <iostream>

int main() {
	int n;
	std::cin >> n;
	int ans = 0, tot = 0, lx = 0;
	for (int i = 0; i < n; ++i) {
		int a;
		std::cin >> a;
		if (a) {
			if (lx) tot -= pow(2, lx - 1);
			if (tot < 0) tot = 0;
			++ans, ++tot, lx = 0;
			if (tot >= 3) ++ans;
			if (tot >= 7) ++ans;
			if (tot >= 30) ++ans;
			if (tot >= 120) ++ans;
			if (tot >= 365) ++ans;
		}
		else ++lx;
	}
	std::cout << ans << std::endl;
}