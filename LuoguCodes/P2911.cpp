//【P2911】[USACO08OCT]牛骨头Bovine Bones - 洛谷 - 20
#include <iostream>
#include <algorithm>
#include <map>

int main() {
	int s1, s2, s3;
	std::cin >> s1 >> s2 >> s3;
	std::map<int, int> m;
	for (int i = 1; i <= s1; ++i)
		for (int j = 1; j <= s2; ++j)
			for (int k = 1; k <= s3; ++k)
				++m[i + j + k];
	int ans = 0, ans2 = -1;
	for (int i = 1; i <= s1 + s2 + s2; ++i)
		//ans = std::max(ans, m[i]);
		if (m[i] > ans)
			ans = m[i], ans2 = i;
	std::cout << ans2 << std::endl;
}