//【P1434】[SHOI2002] 滑雪 - 洛谷 - 10
#include <iostream>
#include <algorithm>

int r, c;
const int kMaxR = 100, kMaxC = 100;
int map[kMaxR + 5][kMaxC + 5], vis[kMaxR + 5][kMaxC + 5], len[kMaxR + 5][kMaxC + 5];
const int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };


int dfs(int x, int y){
	if (len[x][y])
		return len[x][y];
	int step = 1;
	for (int i = 0; i < 4; ++i) {
		int dx = x + dir[i][0], dy = y + dir[i][1];
		if (dx >= 1 && dy >= 1 && dx <= r && dy <= c && map[x][y] > map[dx][dy])
			step = std::max(step, dfs(dx, dy) + 1);
	}
	return len[x][y] = step;
}

int main() {
	std::cin >> r >> c;
	for (int i = 1; i <= r; ++i)
		for (int j = 1; j <= c; ++j)
			std::cin >> map[i][j];
	for (int i = 1; i <= r; ++i)
		for (int j = 1; j <= c; ++j)
			len[i][j] = dfs(i, j);
	int ans = 0;
	for (int i = 1; i <= r; ++i)
		for (int j = 1; j <= c; ++j)
			ans = std::max(ans, len[i][j]);
	std::cout << ans << std::endl;
}