//【P1451】求细胞数量 - 洛谷 - 30
#include <iostream>
int m, n, ans = 0; const int kMaxM = 100, kMaxN = 100; char a[kMaxM + 5][kMaxN + 5]; const int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
void dfs(int x, int y) { if (x < 1 || x > m || y < 1 || y > n || a[x][y] == 48) return; a[x][y] = 48; for (int i = 0; i < 4; ++i) dfs(x + dir[i][0], y + dir[i][1]); } 
int main() { std::cin >> m >> n; for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) std::cin >> a[i][j]; for (int i = 1; i <= m; ++i) for (int j = 1; j <= n; ++j) if (a[i][j] != 48) { ++ans; dfs(i, j); } std::cout << ans << std::endl; }