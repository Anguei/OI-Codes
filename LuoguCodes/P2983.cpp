// -o %s %s.* -O2 -std=c++17 -Wl,--stack=8129334 -D yyfLemon
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cassert>
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

struct Data {
	int p, c;
	Data() = default;
	Data(int p, int c) : p(p), c(c) {}
};

const int N = 100000 + 5;
int n, b, ans = 0;
Data a[N];

void solution() {
	// 无限多 
	n = read(), b = read();
	rep(i, 1, n) a[i].p = read(), a[i].c = read(); // 售价、人（牛）数 
	std::sort(a + 1, a + n + 1, [](const Data &d1, const Data &d2) { return d1.p < d2.p; });
	for (int i = 1; i <= n && b > 0; ++i) {
		ans += std::min(b / a[i].p, a[i].c); // 满足多少头牛 
		b -= std::min(b / a[i].p, a[i].c) * a[i].p; // 耗费多少钱 
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
