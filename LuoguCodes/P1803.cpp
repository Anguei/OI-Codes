//【P1803】凌乱的 yyy - 洛谷 - 0
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> v; 
	for (int i = 1; i <= n; ++i) {
		int _l, _r;
		std::cin >> _l >> _r;
		v.push_back(std::make_pair(_l, _r));
	}
	std::sort(v.begin(), v.end(), [](const std::pair<int, int> &p1, const std::pair<int, int> &p2) {
		return p1.second < p2.second;
	}); 
#ifndef ONLINE_JUDGE
	for (const auto &i : v)
		std::cout << i.first << " " << i.second << std::endl;
#endif
	int ans = 0, cur = v[0].second;
	for (int i = 0; i < v.size(); ++i) 
		if (v[i].first >= cur) {
			++ans;
			cur = v[i].second;
		}
	std::cout << ans + 1 << std::endl;
}