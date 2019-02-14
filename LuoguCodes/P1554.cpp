//【P1554】梦中的统计 - 洛谷 - 0
#include <iostream>
#include <algorithm>

int main() {
	int m, n;
	std::cin >> m >> n;
	int ans[10] = { 0 };
	for (int i = m; i <= n; ++i) {
		int t = i;
		while (t) {
			++ans[t % 10];
			t /= 10;
		}
	}
	for (int i = 0; i < 10; ++i) {
		std::cout << ans[i] << " " ;
	}
	std::cout << std::endl;
}