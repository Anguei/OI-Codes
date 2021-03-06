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

int p, q, a1, a2, n, m;

struct Matrix {
    int a[3][3];
    Matrix() { memset(a, 0, sizeof a); }
    const Matrix operator * (const Matrix &b) {
        Matrix res;
        rep(i, 1, 2) rep(j, 1, 2) rep(k, 1, 2) res.a[i][j] = (res.a[i][j] + a[i][k] * b.a[k][j]) % m;
        return res;
    }
} ans, base;

void init() {
    ans.a[1][1] = a2, ans.a[1][2] = a1;
    base.a[1][1] = p, base.a[2][1] = q, base.a[1][2] = 1;
}

void qpow(int b) {
    while (b) {
        if (b & 1) ans = ans * base;
        base = base * base;
        b >>= 1;
    }
}

void solution() {
    std::cin >> p >> q>> a1 >> a2 >> n >> m;
    if (n == 1) { println(a1); return; }
    if (n == 2) { println(a2); return; }
    init(); qpow(n - 2); println(ans.a[1][1] % m);
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