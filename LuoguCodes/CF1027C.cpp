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
#pragma GCC optimize(3)
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

const int N = 1000000 + 5, max = -1ull / 2;
int n, ansX, ansY, a[N], cnt[N];
double min = max;
std::vector<int> v;

void clear() {
	min = max;
	v.clear();
	//memset(a, 0, sizeof a);
	//memset(cnt, 0, sizeof cnt);
}

int solve() {
	clear();
	n = read();
	rep(i, 1, n) {
		a[i] = read(); ++cnt[a[i]];
		if (cnt[a[i]] == 2) v.push_back(a[i]);
		if (cnt[a[i]] == 4) ansX = ansY = a[i], min = 0.0;
	}
	std::sort(v.begin(), v.end());
	for (int i = 1; i < v.size(); ++i) {
		int x = v[i - 1], y = v[i];
		if (min > (double)(x + y) * (x + y) / x / y) {
			min = (double)(x + y) * (x + y) / x / y;
			ansX = x, ansY = y;
		}
	}
	print(ansX), pc('; ';), print(ansY), pc('; ';); print(ansX), pc('; ';), print(ansY), pc('; ';); puts("");
	for (int i = 1; i <= n; ++i) --cnt[a[i]];
	return 0;
}

signed main() {
#ifdef yyfLocal	
	fileIn;
#endif
	int T = read(); while (T--) solve();
}