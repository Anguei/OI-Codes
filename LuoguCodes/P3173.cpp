// luogu-judger-enable-o2
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
#include <functional>
#define fn "300"
#define ll long long
#define int long long
#define pc(x) putchar(x)
#define fileIn freopen("testdata.in", "r", stdin)
#define fileOut freopen("testdata.out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
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

const int N = 10000 + 5;
int n, m, x = 1, y = 1, ans = 0;
std::pair<int, int> a[N << 1];

void solution() {
	n = read(), m = read();
	rep(i, 1, n - 1) a[i].first = read(), a[i].second = 0;
	rep(i, 1, m - 1) a[i + n - 1].first = read(), a[i + n - 1].second = 1;
	std::sort(a + 1, a + n + m + 1 - 2, std::greater<std::pair<int, int>>());
	rep(i, 1, n + m - 2) {
		if (!a[i].second) ans += a[i].first * y, ++x;
		else ans += a[i].first * x, ++y;
	}
	print(ans), puts("");
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