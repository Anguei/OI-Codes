// luogu-judger-enable-o2
//【P1706】全排列问题 - 洛谷 - 0
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;
	std::vector<int> v;
	for (register int i = 1; i <= n; ++i) v.push_back(i);
	do {
		for (auto &i : v) {
			std::cout << std::setw(5) << i;
			//std::cout << i << " ";
		}
		std::cout << std::endl;
	} while (std::next_permutation(v.begin(), v.end()));
}