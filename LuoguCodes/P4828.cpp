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

const int N = 1000000 + 5, X = 2000 + 5, mod = 998244353;
int n, q, x, y, a[N], c[X][X];

void solution() {
    c[1][1] = 1;
    rep(i, 0, 2000) c[i][0] = 1;
    rep(i, 2, 2000) rep(j, 1, i) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    n = read();
    rep(i, 1, n) a[i] = read();
    q = read();
    while (q--) {
        x = read(), y = read();
        int z = y - 1, ans = 0;
        rep(i, 0, x) {
            if (++z == n + 1) z = 1;
            ans = (ans + c[x][i] * a[z] % mod) % mod;
        }
        print(ans), puts("");
    }
}

signed main() {
#ifdef yyfLocal
    //fileIn;
    //fileOut;
#else  
#ifndef ONLINE_JUDGE   
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);
#endif
#endif
    solution();
}