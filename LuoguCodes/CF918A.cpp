//【CF918A】Eleven - 洛谷 - Ac
#pragma GCC optimize(5)

#include <set>
#include <iostream>

int f[100];

int main() {
	std::set<int> set;
	set.insert(1);
	f[1] = f[2] = 1;
	for (int i = 3; ; ++i) {
		f[i] = f[i - 1] + f[i - 2];
		set.insert(f[i]);
		if (f[i] > 1000)
			break;
	}
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		std::cout << (set.count(i) ? "O" : "o");
	std::cout << std::endl;
}