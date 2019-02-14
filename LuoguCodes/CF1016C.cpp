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
#define ll long long
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x" = " << (x) << std::endl
#else
#define dbg(x) ;
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

const int N = 3000000 + 5;
int n, ans = 0;
int a[N], b[N], s[6][N];

signed main() {
	n = read();
	rep(i, 1, n) a[i] = read(); rep(i, 1, n) b[i] = read(); 
	rep(i, 1, n) s[0][i] = s[0][i - 1] + a[i], s[1][i] = s[1][i - 1] + b[i], s[2][i] = s[2][i - 1] + a[i] * i, s[3][i] = s[3][i - 1] + b[i] * i;
	per(i, n, 1) s[4][i] = s[4][i + 1] + a[i] * (n - i + 1), s[5][i] = s[5][i + 1] + b[i] * (n - i + 1);
	ans = s[1][n] * n + s[2][n] + s[5][1];
	bool state = false; ll now = 0;
	rep(i, 1, n) {
		if (!state) now += ((i << 1) - 1) * a[i] + (i << 1) * b[i];
		else now += ((i << 1) - 1) * b[i] + (i << 1) * a[i];
		state = !state;
		ll tmp = now;
		if (!state) tmp += s[2][n] - s[2][i] + (s[0][n] - s[0][i]) * i + s[5][i + 1] - s[5][n + 1] + (s[1][n] - s[1][i]) * (n + i);
		else tmp += s[3][n] - s[3][i] + (s[1][n] - s[1][i]) * i + s[4][i + 1] - s[4][n + 1] + (s[0][n] - s[0][i]) * (n + i);
		ans = std::max(ans, tmp);
	}
	rep(i, 1, n) ans -= a[i] + b[i];
	print(ans), puts("");
}