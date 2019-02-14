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
#include <deque>
#include <string>
#include <vector>
#include <numeric>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define fn "task"
#define ll long long
// #define int long long
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
	int ap, bp, as, bs;
	Data() = default;
	Data(int ap, int bp, int as, int bs) : ap(ap), bp(bp), as(as), bs(bs) {}
};

const int N = 2000 + 5;
int n, maxP, w;
int dp[N][N];
Data a[N];
std::deque<int> q, dq;

void solution() {
	n = read(), maxP = read(), w = read();
	rep(i, 1, n) {
		int ap = read(), bp = read(), as = read(), bs = read();
		a[i] = Data(ap, bp, as, bs);
	}
	memset(dp, 0xc0, sizeof dp);
	rep(i, 1, n) {
		const int &ap = a[i].ap, &bp = a[i].bp, &as = a[i].as, &bs = a[i].bs;
		rep(j, 0, as) dp[i][j] = -1 * j * ap;
		rep(j, 0, maxP) dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
		if (i - w - 1 >= 0) {
			dq.clear();
	        rep(j, 0, maxP) {
	        	while (!dq.empty() && dq.front() < j - as) dq.pop_front();
	        	while (!dq.empty() && dp[i - w - 1][dq.back()] + dq.back() * ap <= dp[i - w - 1][j] + j * ap) dq.pop_back();
	        	dq.push_back(j);
				dp[i][j] = std::max(dp[i][j], dp[i - w - 1][dq.front()] + dq.front() * ap - j * ap);
	        }
	        dq.clear();
	        per(j, maxP, 0) {
	        	while (!dq.empty() && dq.front() > j + bs) dq.pop_front();
	        	while (!dq.empty() && dp[i - w - 1][dq.back()] + dq.back() * bp <= dp[i - w - 1][j] + j * bp) dq.pop_back();
	        	dq.push_back(j);
				dp[i][j] = std::max(dp[i][j], dp[i - w - 1][dq.front()] + dq.front() * bp - j * bp); 
	        }
		}
	}
	int ans = 0;
	rep(i, 0, maxP) ans = std::max(ans, dp[n][i]);
	print(ans), puts("");
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
