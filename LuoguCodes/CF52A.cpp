//【CF52A】123-sequence - 洛谷 - Ac
#include <cstdio>

#include <map>
#include <iostream>
#include <algorithm>

int main() {
	//std::ios::sync_with_stdio(false);
	std::map<int, int> map;
	register int n;
	std::cin >> n;
	for (register int i = 1; i <= n; ++i) {
		int t;
		//std::cin >> t;
		std::scanf("%d", &t);
		++map[t];
	}
	int max = 0;
	for (const auto &i : map)
		max = std::max(max, i.second);
	std::cout << n - max << std::endl;
}