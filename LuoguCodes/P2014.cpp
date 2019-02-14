// luogu-judger-enable-o2
// -o %s %s.* -O2 -std=c++17 -Wl,--stack=8129334 -D yyfLemon
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

const int N = 300 + 5;
int n, m;
int a[N], dp[N][N], son[N], bro[N];

int dfs(int u, int x) {
	if (u == -1 || x == 0) return 0;
	if (dp[u][x]) return dp[u][x];
	dp[u][x] = dfs(bro[u], x);
	rep(i, 0, x - 1) dp[u][x] = std::max(dp[u][x], a[u] + dfs(son[u], i) + dfs(bro[u], x - i - 1));
	return dp[u][x];
}

void solution() {
	memset(bro, -1, sizeof bro); memset(son, -1, sizeof son);
	n = read(), m = read();
	rep(i, 1, n) {
		int front = read(); a[i] = read();
		bro[i] = son[front];
		son[front] = i;
	}
	print(dfs(0, m + 1));
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
    solution();
}
