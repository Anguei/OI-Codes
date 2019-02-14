//【P1969】积木大赛 - 洛谷 - 70
#include <iostream>

const int kMaxN = 100000;
int h[kMaxN + 5];

int main() {
	std::ios::sync_with_stdio(false);
	register int n;
	std::cin >> n;
	register int last = 0, ans = 0;
	for (register int i = 1; i <= n; ++i) {
		int temp;
		std::cin >> temp;
		if (temp > last)
			ans += temp - last;
		last = temp;
	}
	std::cout << ans << std::endl;
}
