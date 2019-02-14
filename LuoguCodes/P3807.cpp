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

const int N = 100000 + 5;
int n, m, p, fact[N << 1], invFact[N << 1], inv[N << 1];

int lucas(int x, int y) {
    if (x < y) return 0;
    else if (x < p) return fact[x] * invFact[y] * invFact[x - y] % p;
    else return lucas(x / p, y / p) * lucas(x % p, y % p) % p;
}

void solution() {
    n = read(), m = read(), p = read();
    fact[0] = invFact[0] = inv[1] = 1;
    rep(i, 2, n + m) inv[i] = (p - p / i) * inv[p % i] % p; // logs("inited inv[i]");
    rep(i, 1, n + m) fact[i] = fact[i - 1] * i % p, invFact[i] = invFact[i - 1] * inv[i] % p; // logs("inited [inv]f(F)act[i]");
    // dbg(fact[n + m]); dbg(invFact[m]); dbg(invFact[n]);
    println(lucas(n + m, m));
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
    int T = read(); while (T--) solution();
}