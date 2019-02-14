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

struct Seg {
    int l, r;
    Seg() = default; 
    Seg(int l, int r) : l(l), r(r) {}
};

const int N = 300000 + 5;
int n, ans = 0;
Seg a[N], dp1[N], dp2[N];

Seg jiao(const Seg &a, const Seg &b) {
    int l = std::max(a.l, b.l);
    int r = std::min(a.r, b.r);
    return Seg(l, r);
}

int s(const Seg &a) {
    return (a.r > a.l) * (a.r - a.l);
}

void solution() {
    n = read();
    rep(i, 1, n) a[i].l = read(), a[i].r = read();
    dp1[0] = dp2[n + 1] = Seg(-0x7fffffff, 0x7fffffff);
    rep(i, 1, n) dp1[i] = jiao(dp1[i - 1], a[i]);//, dbg(dp1[i].r);
    per(i, n, 1) dp2[i] = jiao(dp2[i + 1], a[i]);
    rep(i, 1, n) ans = std::max(ans, s(jiao(dp1[i - 1], dp2[i + 1])));
    print(ans), puts("");
}

signed main() {
#ifdef yyfLocal
    fileIn;
    //fileOut;
#else  
#ifndef ONLINE_JUDGE   
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);
#endif
#endif
    solution();
}

// Fark Luogu Judging!!!