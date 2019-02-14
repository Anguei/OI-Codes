// luogu-judger-enable-o2
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
#define rep(i, a, b) for (register int i = (a); i <= (b); ++i)
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

int solve() {
	int a0 = read(), a1 = read(), b0 = read(), b1 = read(), p = a0 / a1, q = b1 / b0, ans = 0, upper = sqrt(b1) + 0.5;;
	rep(i, 1, upper)
		if (b1 % i == 0) {
			int j = b1 / i;
			if (i % a1 == 0 && std::__gcd(i / a1, p) == 1 && std::__gcd(b1 / i, q) == 1) ++ans;
			if (i == j) continue;
			if (j % a1 == 0 && std::__gcd(j / a1, p) == 1 && std::__gcd(b1 / j, q) == 1) ++ans;
		}
	return ans;
}

signed main() {
	int T = read(); while (T--) print(solve()), puts("");
}