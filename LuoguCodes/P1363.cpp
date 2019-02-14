//【P1363】幻想迷宫 - 洛谷 - 20
#include <iostream>

const int kMaxNM = 1500;
char a[kMaxNM + 5][kMaxNM + 5];
int vis[kMaxNM + 5][kMaxNM + 5][2];
const int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int n, m;
int startX, startY;

bool dfs(int x, int y) {
	int posX = (x % n + n) % n, posY = (y % m + m) % m;
	
	if (a[posX][posY] == ';#';)
		return false;
	if (vis[posX][posY][0] != 0x3f3f3f3f)
		return vis[posX][posY][0] != x || vis[posX][posY][1] != y;	
	
	vis[posX][posY][0] = x;
	vis[posX][posY][1] = y;
	
	for (int i = 0; i < 4; ++i)
		if (dfs(x + dir[i][0], y + dir[i][1]))
				return true;
	
	return false;
}

int main() {
	while (std::cin >> n >> m) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				vis[i][j][0] = 0x3f3f3f3f;
				std::cin >> a[i][j];
				if (a[i][j] == ';S';) {
					startX = i;
					startY = j;
				}
			}
		
		std::cout << (dfs(startX, startY) ? "Yes" : "No") << std::endl;
	}
}