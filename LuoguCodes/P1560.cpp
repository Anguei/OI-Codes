// luogu-judger-enable-o2
// -o %s %s.* -O2 -std=c++17 -Wl,--stack=8129334 -D yyfLemon
#ifdef yyfLocal
#include <Windows.h>
#endif
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <numeric>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define fn "task"
#define ll long long
#define int long long
#define pc(x) putchar(x)
#define fileIn freopen("testdata.in", "r", stdin)
#define fileOut freopen("testdata.out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x" = " << (x) << std::endl
#define logs(x) std::clog << (x) << std::endl
#else
#define dbg(x) 42
#define logs(x) 42
#endif

int read() {
    int res = 0, flag = 1; char ch = getchar();
    while (!isdigit(ch)) { if (ch == ';-';) flag = -1; ch = getchar(); }
    while (isdigit(ch)) res = res * 10 + ch - 48, ch = getchar();
    return res * flag;
}

void print(int x) {
    if (x < 0) putchar(';-';), x = -x;
    if (x > 9) print(x / 10);
    putchar(x % 10 + 48);
}

const int N = 120 + 5;
int n, b, ans = 0;
int map[N][N];
const int dir[2][2] = { {1, 0}, {0, 1} };
const int dir1[] = { 0, 1, 0, -1 }, dir2[] = { 1, 0, -1, 0 };

/*void dfs(int x, int y, int depth) {
	std::clog << x << " " << y << std::endl;
	if (x == n && y == n) {
		logs("updateAns");
		ans = std::max(ans, depth);
		return;
	}
	for (int i = 0; i < 2; ++i) {
		int dx = x + dir[i][0], dy = y + dir[y][1];
		if (dx < 1 || dy < 1 || dx > n || dy > n) continue;
		if (!map[dx][dy]) {
			map[dx][dy] = true;
			dfs(dx, dy, depth + 1);
			map[dx][dy] = false;
		}
	}
}
*/


namespace Method1 {
	void dfs(int x, int y, int going, int depth) {
	#ifdef yyfLocal
		std::clog << x << " " << y << std::endl;
		// Sleep(10);
	#endif
		ans = std::max(ans, depth);
		if (map[x + dir1[going]][y + dir2[going]] == 1) {
			// map[x][y] = 1;
			map[x][y] = 2;
			dfs(x + dir1[going], y + dir2[going], going, depth + 1);
			map[x][y] = 1;
		} else if (map[x + dir1[going]][y + dir2[going]] == 0) {
			rep(i, 0, 3) {
				if (map[x + dir1[i]][y + dir2[i]] == 1 && ((i + going) & 1)) {
					// map[x][y] = 1;
					map[x][y] = 2;
					dfs(x + dir1[i], y + dir2[i], i, depth + 1);
					map[x][y] = 1;
				}
			}
		}
	}
	
	void solution() {
		n = read(), b = read();
		rep(i, 1, n) rep(j, 1, n) map[i][j] = 1;
		rep(i, 1, b) {
			std::string s;
			std::cin >> s;
			int line = s[0] - 64;
			int col = std::stoi(s.substr(1));
			map[line][col] = 0;
		}
		dfs(1, 1, 0, 1);
		dfs(1, 1, 1, 1);
		//print(ans << 1 | 1), puts("");
		print(ans), puts("");
	}
}

namespace Method2 {
	void dfs(int x, int y, int going, int depth) {
	#ifdef yyfLocal
		std::clog << x << " " << y << std::endl;
		// Sleep(10);
	#endif
		ans = std::max(ans, depth);
		if (map[x + dir1[going]][y + dir2[going]] == 0) {
			// map[x][y] = 1;
			map[x][y] = 2;
			dfs(x + dir1[going], y + dir2[going], going, depth + 1);
			map[x][y] = 0;
		} else if (map[x + dir1[going]][y + dir2[going]] == 1) {
			rep(i, 0, 3) {
				if (map[x + dir1[i]][y + dir2[i]] == 1 && ((i + going) & 1 ^ 1)) {
					// map[x][y] = 1;
					map[x][y] = 2;
					dfs(x + dir1[i], y + dir2[i], i, depth + 1);
					map[x][y] = 0;
				}
			}
		}
	}
	
	void solution() {
		n = read(), b = read();
		rep(i, 1, b) {
			std::string s;
			std::cin >> s;
			int line = s[0] - 64;
			int col = std::stoi(s.substr(1));
			map[line][col] = 1;
		}
		dfs(1, 1, 0, 1);
		dfs(1, 1, 1, 1);
		//print(ans << 1 | 1), puts("");
		print(ans), puts("");
	}
}

signed main() {
#ifdef yyfLocal
    fileIn;
    //fileOut;
#else
#ifndef ONLINE_JUDGE
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);
#endif
#endif
    Method1::solution();
    // Method2::solution();
}
