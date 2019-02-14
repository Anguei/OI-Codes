//【P1540】机器翻译 - 洛谷 - 0 
#include <iostream> 
#include <vector>
#include <algorithm>

int main() {
	int m, n;
	std::cin >> m >> n;
	std::vector<int> v;
	int ans = 0;
	int t;
	while (std::cin >> t) {
		if (std::find(v.begin(), v.end(), t) == v.end()) {
			v.push_back(t);
			++ans;
		}
		if (v.size() > m)
			v.erase(v.begin());
	}
	std::cout << ans << std::endl;
}