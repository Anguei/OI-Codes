//【P1181】数列分段Section I - 洛谷 - 20
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> v;
	while (std::cin >> n)
		v.push_back(n);
	n = v.size();
	int ans = 0, pos = 0, sum = 0;
	for (register unsigned i = 0; i < n; ++i) {
		sum += v[i];
		if (sum > m) {
			sum = 0;
			++ans;
			--i;
		}
	}
	std::cout << ans + 1 << std::endl;
}