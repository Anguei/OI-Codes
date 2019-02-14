#include <bits/stdc++.h>

int main() {
	int ans[31] = { 0 };
	int m, n; std::cin >> m >> n;
	auto query = [m, n](int x) {
		std::cout << x << std::endl;
		int fb; std::cin >> fb;
		if (!fb) exit(0);
		return fb;
	};
	for (int i = 0; i < n; ++i) ans[i] = query(1);
	int x = 0, a = 0;
	for (int i = 29; i >= 0; --i) {
		if (x + (1 << i) > m) continue;
		if (query(x + (1 << i)) * ans[a++ % n] == 1) x += (1 << i);
	}
}