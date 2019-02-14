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
#define rep(i, a, b) for (register int i = (a); i <= (b); ++i)
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

const int N = 5000000 + 5, mod = 998244353;
int fact[N], inv[N], invFact[N], powed[N], g[N];

void init() {
    fact[0] = invFact[0] = inv[1] = powed[0] = g[0] = 1; g[1] = 0;
    rep(i, 2, N - 1) inv[i] = (mod - mod / i) * inv[mod % i] % mod, g[i] = 4 * i % mod * (i - 1) % mod * (g[i - 1] + 2 * (i - 1) * g[i - 2] % mod) % mod;
    rep(i, 1, N - 1) fact[i] = fact[i - 1] * i % mod, invFact[i] = invFact[i - 1] * inv[i] % mod, powed[i] = powed[i - 1] * 2 % mod;
}

#define C(n, m) (fact[(n)] * invFact[(n) - (m)] % mod * invFact[(m)] % mod)
#define mul(x) ((x) * (x) % mod)
void solution() {
    int n = read(), k = read();
    println(mul(C(n, k)) * fact[k] % mod * powed[k] % mod * g[n - k] % mod);
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
    init(); int T = read(); while (T--) solution();
}