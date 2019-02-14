//【P1162】填涂颜色 - 洛谷 - 40
#include <iostream> 

int n;
bool vis[40][40];
int map[40][40];
bool edge;
int dir[8][2] = { { 1, 0 },{ -1, 0 },{ 0, 1 },{ 0, -1 } };

void dfs(int x, int y) { 
	if (x > n || x < 1 || y > n || y < 1) { 
		edge = true;
		return;
	}
	if (vis[x][y]) return; 
	vis[x][y] = true; 
	for (int i = 0; i < 4; i++) { 
		dfs(x + dir[i][0], y + dir[i][1]);
	}
	map[x][y] = 2; 
}

int main() {
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			std::cin >> map[i][j];
			if (map[i][j] == 1) vis[i][j] = true;
		}
	}
	for (int i = 1; i <= n; i++) { 
		for (int j = 1; j <= n; j++) {
			if (vis[i][j]) continue; 
			edge = false; 
			dfs(i, j);
			if (edge) {
				for (int u = 1; u <= n; u++) {
					for (int v = 1; v <= n; v++) {
						if (map[u][v] == 2) map[u][v] = 0;
					}
				} 
				continue; 
			}
			for (int u = 1; u <= n; u++) { 
				for (int v = 1; v <= n; v++) {
					std::cout << map[u][v] << " ";
				}
				std::cout << std::endl;
			}
			return 0; 
		}
	}
}