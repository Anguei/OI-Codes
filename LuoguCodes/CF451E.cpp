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

const int N = 20 + 5, mod = 1000000007;
int n, s, ans = 0, inv[N], f[N];

int qpow(int a, int b) { int res = 1; while (b) { if (b & 1) res = res *a % mod; a = a * a % mod; b >>= 1; } return res % mod; }

int C(int n, int m) {
	if (n < 0 || m < 0 || n < m) return 0;
	int res = 1;
	n %= mod;
	if (n == 0 || m == 0) return 1;
	rep(i, 0, m - 1) res = (long long)res * (n - i) % mod;
	rep(i, 1, m) res = (long long)res * inv[i] % mod;
	return res % mod;
}

void solution() {
    rep(i, 1, 21) inv[i] = qpow(i, mod - 2);
    n = read(), s = read(); rep(i, 1, n) f[i] = read();
    rep(i, 0, (1 << n) - 1) if (!i) ans = (ans + C(n + s - 1, n - 1)) % mod; else {
        int t = n + s, p = 0;
        rep(j, 0, n - 1) if (i >> j & 1) ++p, t -= f[j + 1];
        t -= p + 1;
        ans = (p & 1) ? (ans - C(t, n - 1)) % mod : (ans + C(t, n - 1)) % mod;
    }
    print((ans + mod) % mod), puts("");
}

signed main() {
#ifdef yyfLocal
    fileIn;
    // fileOut;
#else  
#ifndef ONLINE_JUDGE   
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);
#endif
#endif
    logs("main.exe");
    solution();
}