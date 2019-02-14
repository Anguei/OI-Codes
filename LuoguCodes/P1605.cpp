//【P1605】迷宫 - 洛谷 - 10 
#include <iostream>

int n, m, t, sx, sy, fx, fy, ans = 0;
bool vis[6][6] = { 0 }, is_f[6][6] = { 0 };
int dir[4][2] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } };

void dfs(int x, int y) {
	if (x < 1 || y < 1 || x > n || y > m)
		return;
	if (is_f[x][y] || vis[x][y])
		return;
	if (x == fx && y == fy) {
		++ans;
		return;
	}
	for (int i = 0; i < 4; ++i) {
		vis[x][y] = true;
		dfs(x + dir[i][0], y + dir[i][1]);
		vis[x][y] = false;
	}
}

int main() {
	std::cin >> n >> m >> t;
	std::cin >> sx >> sy >> fx >> fy;
	for (int i = 0; i < t; ++i) {
		int x, y;
		std::cin >> x >> y;
		is_f[x][y] = true;
	}
	dfs(sx, sy);
	std::cout << ans << std::endl;
}