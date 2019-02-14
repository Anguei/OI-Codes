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
#define dbg2(x, y) std::clog << #x" = " << (x) << ", " << #y " = " << (y) << std::endl
#else
#define dbg(x) 42
#define logs(x) 42
#define dbg2(x, y) 42
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

namespace Baoli {
	int n, l, I, cur = 0;
	bool digit[35];
	
	void inc(int x) {
		cur += digit[x] ? -1 : 1;
		digit[x] ^= 1;
		if (!digit[x]) inc(x + 1);
	}
	
	void solution() {
		n = read(), l = read(), I = read() - 1;
		while (I) {
			inc(0);
			I -= (cur <= l);
		}
		per(i, n - 1, 0) pc(digit[i] + 48); puts("");
	}
}

namespace Zhengjie {
	int n, l, I;
	int dp[35][35];
	bool tmp = 0;

	void solution() {
		n = read(), l = read(), I = read();
		rep(i, 1, n) dp[i][0] = dp[i][i] = 1;
		rep(i, 1, l) dp[0][i] = 1;
		rep(i, 1, n) rep(j, 1, std::min(i, l)) dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
		rep(i, 1, n) rep(j, 1, l) dp[i][j] += dp[i][j - 1];
		per(i, n, 1) tmp = ((dp[i - 1][l] < I) && (l > 0)), pc(tmp + 48), I -= tmp * dp[i - 1][l], l -= tmp/*, dbg2(I, l)*/; puts("");
		logs("1001001100101100001010010011011");
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
    // Baoli::solution();
    Zhengjie::solution();
}
