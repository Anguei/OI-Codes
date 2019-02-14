//【P1496】火烧赤壁 - 洛谷 - 30
#include <iostream>
#include <algorithm>

const int kMaxN = 20000;
std::pair<int, int> edges[kMaxN + 5];

int main() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> edges[i].first >> edges[i].second;
	std::sort(edges + 1, edges + n + 1);
	int l = edges[1].first, r = edges[1].second;
	long long ans = r - l;;
	for (int i = 2; i <= n; ++i) {
		if (edges[i].second <= r)
			continue;
		if (edges[i].first < r)
		 	ans += edges[i].second - r;
		else {
			ans += edges[i].second - edges[i].first;
			l = edges[i].first;
		}
		r = edges[i].second;
	}
	std::cout << ans << std::endl;
}
