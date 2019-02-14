#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
#define ll long long
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x" = " << (x) << std::endl
#else
#define dbg(x) x
#endif

signed main() {
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
	int k;
	while (std::cin >> k) {
		std::vector<std::pair<int, int>> ans; 
		rep(y, k + 1, (k << 1)) if (k * y % (y - k) == 0) ans.push_back(std::make_pair(k * y / (y - k), y));
		std::cout << ans.size() << std::endl;
		for (const auto &i : ans) std::cout << "1/" << k << " = 1/" << i.first << " + 1/" << i.second << std::endl;
	}
}