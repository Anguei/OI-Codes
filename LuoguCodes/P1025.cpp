//【P1025】数的划分 - 洛谷 - 0
#include <iostream>

int n, k, ans = 0;

void dfs(int last, int sum, int cur) {
	if (cur == k)  {
		if (sum == n)
			++ans;
		return;
	}
	//for (int i = last; sum + i * (k - cur) <= n; ++i)	
	for (int i = last; sum + i <= n; ++i)
		dfs(i, sum + i, cur + 1);
}

int main() {
	std::cin >> n >> k;
	dfs(1, 0, 0);
	std::cout << ans << std::endl;
}