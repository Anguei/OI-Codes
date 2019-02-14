//【P1658】购物 - 洛谷 - 0 
#include <queue>
#include <vector>
#include <iostream> 
#include <algorithm>
#include <functional>

int main() {
	int x, n;
	std::cin >> x >> n;
	std::vector<int> coins;
	//std::priority_queue<int, std::vector<int>, std::less<int>> coins;
	for (int i = 0; i < n; ++i) {
		int t;
		std::cin >> t;
		coins.push_back(t);
	}
	std::sort(coins.begin(), coins.end(), std::greater<int>());
	if (coins.back() != 1) {
		std::cout << -1 << std::endl;
		return 0;
	}
	int ans = 0, sum = 0;
	while (sum < x) {
		for (int i = 0; i < coins.size(); ++i)
			if (coins[i] <= sum + 1) {
				++ans;
				sum += coins[i];
				break;
			}
	}
	//while (x > 0 && !coins.empty()) {
	//	//std::clog << x << " " << coins.top() << std::endl;
	//	if (x / coins.top() > 0) {
	//		ans += x / coins.top();
	//		x -= x / coins.top() * coins.top();
	//	}
	//	coins.pop();
	//}
	std::cout << ans << std::endl;
}