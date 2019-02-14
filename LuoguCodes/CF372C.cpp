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
	int a, b, t;
	Data() = default;
	Data(int a, int b, int t) : a(a), b(b), t(t) {}
};

struct Node {
	int pos, val;
	Node() = default;
	Node(int pos, int val) : pos(pos), val(val) {}
};

int n, m, d, sumB = 0;
int a[300 + 5], b[300 + 5], t[300 + 5];
int dp[2][150000 + 5];
Node dq[150000 + 5];

void solution() {
	n = read(), m = read(), d = read();
	rep(i, 1, m) {
		a[i] = read(), b[i] = read(), t[i] = read();
		sumB += b[i];
	}
	rep(i, 1, n) dp[0][i] = abs(a[1] - i);
	int now = 0, limit = 0, head = 0, tail = 0;
	
	rep(i, 2, m) {
		limit = t[i] - t[i - 1]; limit *= d;
		limit = std::min(limit, n);
		head = tail = 0;
		rep(k, 1, limit) {
			while (head < tail && dp[now][k] < dq[tail - 1].val) --tail;
			dq[tail].val = dp[now][k], dq[tail++].pos = k;
		}
		rep(j, 1, n) {
			int l = j - limit, r = j + limit;
			if (l <= 0) l = 1;
			while (head < tail && dq[head].pos < l) ++head;
			if (r <= n) {
				while (head < tail && dp[now][r] < dq[tail - 1].val) --tail;
				dq[tail].val = dp[now][r], dq[tail++].pos = r;
			}
			dp[now ^ 1][j] = dq[head].val + abs(a[i] - j);
		}
		now ^= 1;
	}
	
	int min = dp[now][1];
	rep(i, 2, n) min = std::min(min, dp[now][i]);
	print(sumB - min), puts("");
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
