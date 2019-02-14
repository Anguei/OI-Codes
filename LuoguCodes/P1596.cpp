//【P1596】[USACO10OCT] 湖计数 Lake Counting - 洛谷 - 0 
#include <iostream> 

const int kMaxN = 100;
const int kMaxM = 100;

int n, m;
char map[kMaxN + 5][kMaxM + 5];
bool vis[kMaxN + 5][kMaxM + 5];
const int dir[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };

void dfs(int x, int y)
{
	if (x > n || x < 1 || y > m || y < 1)
		return;
	if (vis[x][y])
		return;
	if (map[x][y] != ';W';)
		return;
		
	vis[x][y] = true;
	for (int i = 0; i < 8; ++i)
	{
		int dx = x + dir[i][0];
		int dy = y + dir[i][1];
		dfs(dx, dy);
	}
}

int main()
{
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			std::cin >> map[i][j];
			
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (!vis[i][j] && map[i][j] == ';W';)
			{
				++ans;
				dfs(i, j);
			}
	std::cout << ans << std::endl;
}