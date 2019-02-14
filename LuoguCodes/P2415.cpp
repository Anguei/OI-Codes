//【P2415】集合求和 - 洛谷 - 80
#include <cmath>
#include <iostream>
#include <set> 
#include <vector>
#include <algorithm>

int main() {
	int x;
	std::set<int> s;
	std::vector<int> v;
	unsigned long long ans = 0, count = 0, sum = 0;
	while (std::cin >> x) {
		s.insert(x);
		sum += x;
		++count;
	}
	for (auto i : s) v.push_back(i);
	ans += pow(2, count - 1);
	sum += std::accumulate(v.begin(), v.end(), 0);
	sum -= std::accumulate(v.begin(), v.end(), 0);
	ans *= sum;
	std::cout << ans << std::endl;
}