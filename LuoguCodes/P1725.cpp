#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
//#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x" = " << (x) << std::endl
#else
#define dbg(x) 
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
int a[N], dp[N];
std::deque<std::pair<int, int> > dq;

int main() {
	int n = read(), l = read(), r = read();
	rep(i, 1, n + 1) a[i - 1] = read();
	int pos = 0;
	rep(i, l, n) {
		while (!dq.empty() && dq.back().second < dp[pos]) dq.pop_back();
		std::pair<int, int> x; x.first = pos; x.second = dp[pos];
		dq.push_back(x);
		while (dq.front().first + r < i) dq.pop_front();
		dp[i] = a[i] + dq.front().second;
		++pos;
	}
	int ans = -0x7fffffff;
	rep(i, n - r + 1, n) ans = std::max(ans, dp[i]);
	print(ans), puts("");
}