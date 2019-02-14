//【P2058】海港 - 洛谷 - 100
#pragma GCC optimize(2)

#include <queue>
#include <vector>
#include <utility> 
#include <iostream>
#include <unordered_map>

//int map[100000 + 5];
std::vector<int> map(100000 + 5);

int main() {
	int n, t, k, ans = 0;
	std::cin >> n;
	//std::unordered_map<int, int> map;
	std::queue<std::pair<int, int>> q;
	while (n--) {
		std::cin >> t >> k;
		while (k--) {
			int nation;
			std::cin >> nation;
			q.push(std::make_pair(t, nation));
			if (!map[nation]++)
				++ans;
		}
		while (q.back().first - q.front().first >= 86400) {
			if (!--map[q.front().second])
				--ans;
			q.pop();
		}
		std::cout << ans << std::endl;
	}
}
