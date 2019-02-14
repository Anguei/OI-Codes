//【P1443】马的遍历 - 洛谷 - 0
#include <cstring>
#include <queue>
#include <iostream> 
#include <iomanip>

int n, m, mx, my;
int map[405][405];
int dir1[8] = {-1, -1, 1, 1, -2, -2, 2, 2};
int dir2[8] = {-2, 2, -2, 2, -1, 1, 1, -1};
bool vis[405][405];

//typedef std::pair<int, int> pii;

struct Point {
	int x, y, step;
	Point(int x, int y, int step) : x(x), y(y), step(step) {}
};

void bfs(int step) {
	std::queue<Point> q;
	q.push(Point(mx, my, 0));
	while (q.size()) {
		//pii u = q.front(); q.pop();
		Point u = q.front(); q.pop();
		//vis[u.first][u.second] = true;
		vis[u.x][u.y] = true;
		++u.step;
		for (int i = 0; i < 8; ++i) {
			Point now = u;
			now.x += dir1[i];
			now.y += dir2[i];
			if (now.x < 1 || now.x > n || now.y < 1 || now.y > m || vis[now.x][now.y]) continue;
			map[now.x][now.y] = now.step;
			//vis[now.first][now.second] = true;
			vis[now.x][now.y] = true;
			q.push(now);
		}
	}
}

int main() {
	std::cin >> n >> m >> mx >> my;
	memset(map, -1, sizeof map);
	memset(vis, false, sizeof vis);
	map[mx][my] = 0;
	bfs(0);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			std::cout << std::left << std::setw(5) << map[i][j];
		}
		std::cout << std::endl;
	}
	return 0;
}