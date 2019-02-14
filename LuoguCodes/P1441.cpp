// luogu-judger-enable-o2
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <string>
#include <vector>
#include <numeric>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define fn "testdata"
#define ll long long
#define int long long
#define pc(x) putchar(x)
#define endln putchar(';\n';)
#define println(x) print(x), endln
#define fileIn freopen("testdata.in", "r", stdin)
#define fileOut freopen("testdata.out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
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

const int N = 20 + 5;
#ifndef yyfLocal
	const int SIZE = 100 * 20 + 5;
#else
	const int SIZE = 7;
#endif
int n, m, ans = 0, a[N];

int popcount(int x) { int res = 0; while (x) res += (x & 1), x >>= 1; return res; } 

void solution() {
	n = read(), m = read(); rep(i, 0, n) a[i] = read();
	rep(i, 0, (1 << n)) if (popcount(i) == n - m) {
		std::bitset<SIZE> bs; bs[0] = true;
		rep(j, 0, n) if (i & (1 << j)) bs |= bs << a[j];
		bs[0] = false; ans = std::max(ans, static_cast<int>(bs.count()));
		logs(bs);
	}
	println(ans);
}

signed main() {
#ifdef yyfLocal
    fileIn;
    // fileOut;
#else
#ifndef ONLINE_JUDGE
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);
#endif
#endif
    logs("main.exe");
    solution();
}
