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

const int N = 100 + 5;
int n, m;
int a[N], b[N], ans[N];
const std::string out[] = { "o", "i", "Impossible" };

void dfs(int u, int v) {
	if (ans[u] == -1) {
		ans[u] = v;
		rep(i, 1, m) {
			if (a[u] ^ a[v] && b[u] ^ b[v]) {
				if (a[u] < a[i] && b[u] < b[i] && a[i] < b[u]) dfs(i, v ^ 1);
				if (a[u] > a[i] && b[u] > b[i] && a[u] < b[i]) dfs(i, v ^ 1);
			}
		}
	} else if (ans[u] ^ v) exit((puts(out[2].data()), 0));
}

void solution() {
	n = read(), m = read();
	rep(i, 1, m) {
		a[i] = read(), b[i] = read();
		if (a[i] > b[i]) std::swap(a[i], b[i]);
	}
	memset(ans, -1, sizeof ans);
	rep(i, 1, m) if (ans[i] == -1) dfs(i, 0);
	rep(i, 1, m) pc(out[ans[i]][0]);
}

signed main() {
#ifdef yyfLocal
    fileIn;
    fileOut;
#else
#ifndef ONLINE_JUDGE
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);
#endif
#endif
    solution();
}
