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

const char *solve() {
	int a = read(), b = read(), x = read(), y = read(), g = std::__gcd(a, b) << 1;
	auto check = [g](int a, int b) { return a % g == 0 && b % g == 0; };
	return (check(x, y) || check(x + a, y + b) || check(x + b, y + a) || check(x + a + b, y + a + b)) ? "Y" : "N";
}

signed main() {
	int T = read(); while (T--)  puts(solve());
}