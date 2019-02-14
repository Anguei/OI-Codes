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

int n, k, dp[100 + 5];
std::pair<int, int> opt[100 + 5];

void clear() {
	memset(dp, 0xc0, sizeof dp);
	dp[0] = 0;
	memset(opt, 0, sizeof opt);
}

void solution() {
	clear();
	n = read(), k = read();
	rep(i, 1, n) {
		int in = (read() % k + k) % k;
		int cnt = 0;
		per(j, k - 1, 0) if (dp[j] == i - 1) opt[++cnt] = std::make_pair(i - 1, j);
		per(j, cnt, 1) {
			dp[(opt[j].second + in) % k] = opt[j].first + 1;
			dp[(opt[j].second - in + k) % k] = opt[j].first + 1;
		}
	}
	puts(dp[0] == n ? "Divisible" : "Not divisible");
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
    int T = read(); while (T--) solution();
}
