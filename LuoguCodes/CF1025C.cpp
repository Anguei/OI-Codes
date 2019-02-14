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

const int N = 200000 + 5;
int dp[N];

signed main() {
	std::string s;
	std::cin >> s;
	int n = s.size();
	s += s;
	s = " " + s;
	dp[1] = 1;
	rep(i, 2, n * 2) if (s[i - 1] != s[i]) dp[i] = dp[i - 1] + 1; else dp[i] = 1;
	int ans = 0;
	rep(i, 1, n * 2) ans = std::max(ans, dp[i]);
	print(std::min(ans, n)), puts("");

}