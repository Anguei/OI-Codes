#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
#define ll long long
#define int long long
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

ll sum(ll x) {
	if (x <= 1) return x;
	ll res = 0;
	ll l = 1, r = 0;
	while (l <= x) {
		r = x / (x / l);
		res += (x / l) * (l + r) * (r - l + 1) >> 1;
		l = ++r;
	}
	return res;
}

signed main() {
	ll x = read(), y = read();
	print(sum(y) - sum(x - 1)), puts("");
}