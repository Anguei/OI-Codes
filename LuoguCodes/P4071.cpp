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
#include <iomanip>
#include <iostream>
#include <algorithm>
#define fn "2034"
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

const int N = 1000000 + 5, p = 1e9 + 7.5;
int n, m, fact[N], invFact[N], inv[N], d[N];

void init() {
    fact[0] = invFact[0] = inv[1] = 1;
    rep(i, 2, N) inv[i] = (p - p / i) * inv[p % i] % p;
    rep(i, 1, N) fact[i] = fact[i - 1] * i % p, invFact[i] = invFact[i - 1] * inv[i] % p;
    d[0] = 1, d[1] = 0, d[2] = 1; rep(i, 3, N) d[i] = (i - 1) * (d[i - 1] + d[i - 2]) % p;//, dbg(d[i]);
}

inline int C(int n, int m) {
    return fact[n] * invFact[m] % p * invFact[n - m] % p;
}

// C(n, m) * d[n - m]
void solution() {
    n = read(), m = read();
    println(C(n, m) * d[n - m] % p);
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