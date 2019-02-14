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

const int N = 1000000 + 5;
int n, a[N], dp[N];

void solution() {
	/*n = read();
	rep(i, 1, n) a[i] = read();
	// 开氧气溢出 
	rep(i, 1, n) dp[i] = std::min(dp[i - 1] + a[i], std::min(dp[i - 2] + a[i - 1], dp[i - 3] + a[i - 2])), dbg(dp[i]);
	print(dp[n]); puts("");*/
	n = read();
	rep(i, 1, n) a[i] = read();
	rep(i, 1, n + 1) {
		//if (i >= 3)
		dp[i] = std::min(dp[i - 1] + a[i], std::min(dp[i - 2] + a[i - 1], dp[i - 3] + a[i - 2]));
		//else if (i >= 2) dp[i] = std::min(dp[i - 1] + a[i], dp[i - 2] + a[i - 1]);
		//else if (i >= 1) dp[i] = a[i];
	}
	//print(dp[n]);
	print(std::min(dp[n], dp[n + 1])), puts("");
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
