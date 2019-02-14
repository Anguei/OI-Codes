//【P3368】【模板】树状数组 2 - 洛谷 - 0
#include <iostream>

const int kMaxN = 500000;
int n, m;
int c[kMaxN + 5];

constexpr int lowbit(int x) {
	return x & (-x);
}

int sum(int i) {
	int res = 0;
	while (i > 0) {
		res += c[i];
		i -= lowbit(i);
	}
	return res;
}

void update(int i, int val) {
	while (i <= n) {
		c[i] += val;
		i += lowbit(i);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin >> n >> m;
	int pre = 0;
	for (int i = 1; i <= n; ++i) {
		int val;
		std::cin >> val;
		update(i, val - pre);
		pre = val;
	}
	for (int i = 1; i <= m; ++i) {
		int command;
		std::cin >> command;
		if (command == 1) {
			int x, y, val;
			std::cin >> x >> y >> val;
			update(x, val);
			update(y + 1, -val);
		} else if (command == 2) {
			int x;
			std::cin >> x;
			std::cout << sum(x) << std::endl;
		}
	}
}