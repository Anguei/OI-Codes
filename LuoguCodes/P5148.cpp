// luogu-judger-enable-o2
// luogu-judger-enable-o2
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

const int M = 500000 + 5, p = 1e9 + 7.5;
int a[M], n, m, k, q;

int qpow(int a, int b) { a %= p; int res = 1; while (b) { if (b & 1) (res *= a) %= p; (a *= a) %= p; b >>= 1; } return res; }
int f(int x) { int tot = 0; per(i, m, 0) tot = (tot + a[i] * qpow(x, i) % p) % p; return tot; }
int fact(int x) { int res = 1; rep(i, 1, x) (res *= i) %= p; return res;}

void solution() {
    // n * (n - 1) * (n - 2) * ... * (n - k + 1)
    n = read(), m = read(), k = read(), q = read(); rep(i, 0, m) a[i] = read();
    int ans = 1; rep(i, n - k + 1, n) (ans *= i) %= p; dbg(ans); println(ans * f(q) % p * qpow(fact(k), p - 2) % p);
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