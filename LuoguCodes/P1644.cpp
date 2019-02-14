//【P1644】跳马问题 - 洛谷 - 0
#include <iostream>

int ans = 0, n, m;
int dir[4][2] = { {2, 1}, {1, 2}, {2, -1}, {1, -2} };

inline void dfs(int x, int y) {
	if (x == m && y == n) 
		++ans;
	if (x < 0 || y < 0 || x > m || y > n) 
		return;
	for (int i = 0; i < 4; ++i) 
		dfs(x + dir[i][0], y + dir[i][1]);
}

int main() {
	std::cin >> n >> m;
	dfs(0, 0);
	std::cout << ans << std::endl;
}