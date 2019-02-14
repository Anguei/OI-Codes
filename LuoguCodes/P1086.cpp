//【P1086】花生采摘 - 洛谷 - 30 
#include <cmath>
#include <iostream> 
#include <algorithm>

const int MAXN = 20, MAXM = 20;
int map[MAXM + 3][MAXN + 3];
int ans = 0;
int n, m, k;

void dfs(int x, int y, int rest) {
	int max, maxx, maxy;
	max = maxx = maxy = -2147483648;
	for (int i = 1; i <= m; ++i) 
		for (int j = 1; j <= n; ++j) 
			if (map[i][j] > max) {
				max = map[i][j];
				maxx = i, maxy = j;
			}	
	//if (x == 0)
		//x = maxx;
	if (!y) 
		y = maxy;
	if (rest < abs(x - maxx) + abs(y - maxy) + maxx + 1 || map[maxx][maxy] == 0) // 移动时间 + 返回时间 || 这里没有 
		return;
	ans += map[maxx][maxy];
	map[maxx][maxy] = 0;
	dfs(maxx, maxy, rest - abs(x - maxx) -abs(y - maxy) - 1);
}

int main() {
	std::cin >> m >> n >> k;
	int max, maxx, maxy;
	max = maxx = maxy = 0;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			std::cin >> map[i][j];
	dfs(0, 0, k);
	std::cout << ans << std::endl;
} 