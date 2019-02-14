#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
//#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
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

const int N = 500000 + 5;

int st[N][20];

int main() {
	int n = read(), m = read();
	rep(i, 1, n) st[i][0] = st[i - 1][0] + read();
	for (int j = 1; (1 << j) <= n; ++j) for (int i = 1; i + (1 << j) - 1 <= n; ++i) st[i][j] = std::min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
	int k = log2(m), ans = 0;
	rep(i, m, n) ans = std::max(ans, st[i][0] - std::min(st[i - m][k], st[i - (1 << k) + 1][k]));
	print(ans), puts("");
}