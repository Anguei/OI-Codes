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
#include <iomanip>
#include <iostream>
#include <algorithm>
#define fn "testdata"
#define ll long long
#define int long long
#define pc(x) putchar(x)
#define endln putchar(';\n';)
#define println(x) print(x), endln
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

const int N = 1000 + 5, mod = 998244353;
int fact[N], inv[N], invFact[N], powed[N], g[N] = { 1, 0 };

void init() {
    fact[0] = invFact[0] = inv[1] = powed[0] = 1;
    rep(i, 2, N - 1) inv[i] = (mod - mod / i) * inv[mod % i] % mod;;
    rep(i, 1, N - 1) fact[i] = fact[i - 1] * i % mod;
    rep(i, 1, N - 1) invFact[i] = invFact[i - 1] * inv[i] % mod;
    rep(i, 1, N - 1) powed[i] = powed[i - 1] * 2 % mod;
    rep(i, 2, N - 1) g[i] = 4 * i % mod * (i - 1) % mod * (g[i - 1] + 2 * (i - 1) * g[i - 2] % mod) % mod;
}

#define C(n, m) (fact[(n)] * invFact[(n - m)] % mod * invFact[(m)] % mod)
void solution() { int n = read(); rep(i, 0, n) println(C(n, i) * C(n, i) % mod * fact[i] % mod * powed[i] % mod * g[n - i] % mod); }

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
    init(); int T = read(); while (T--) solution();
}