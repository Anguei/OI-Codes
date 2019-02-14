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
#define ll unsigned long long
#define int unsigned long long
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

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int lcm(int a, int b) {
	return a / gcd(a, b) * b;
}

const int N = 1000010;
int a[N], b[N];

signed main() {
	int n = read();
	int fuck;
	for (int i = 1; i <= n; ++i) {
		a[i] = read(), b[i] = read();
		if (i == 1) fuck = a[i] * b[i];
		else fuck = gcd(fuck, a[i] * b[i]);
	}
	if (fuck == 1) return puts("-1"), 0;
	for (int i = 1; i <= n; ++i) {
		int c = gcd(a[i], fuck);
		if (c != 1) fuck = c;
		else fuck = gcd(b[i], fuck); 
	}
	print(fuck), puts("");
}