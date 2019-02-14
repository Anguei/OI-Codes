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
#define ll long long
#define int long long
#define pc(x) putchar(x)
#define fileIn freopen("testdata.in", "r", stdin)
#define fileOut freopen("testdata.out", "w", stdout)
#define rep(i, a, b) for (register int i = (a); i <= (b); ++i)
#define per(i, b, a) for (register int i = (b); i >= (a); --i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x" = " << (x) << std::endl
#else
#define dbg(x) x
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

int solve() {
	int n = read(), cnt = 0, last = 0;
	int ans[100] = { 0 };
	for (int i = 2, j = 2; j <= n; j += i, last = n - j + i) ans[++cnt] = i++;
	for (int i = 0; last--; i = (i + 1) % cnt) ++ans[cnt - i];
	rep(i, 1, cnt) printf("%lld%c", ans[i], " \n"[i == cnt]);
	return 0;
}

signed main() {
	int T = read();
	rep(i, 0, T - 1) {
		if (i) puts("");
		solve();
	}
}