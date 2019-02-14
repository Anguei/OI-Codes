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
int n, m, a[N], b[N], ans = 0;

bool find(int x) {
    int l = 1, r = m + 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (b[mid] == x) return true;
        if (b[mid] < x) l = mid + 1;
        else r = mid;
    }
    return false;
}

void solution() {
    n = read(), m = read();
    rep(i, 1, n) a[i] = read(); rep(i, 1, m) b[i] = read();
    std::sort(b + 1, b + m + 1);
    rep(i, 1, n) if (find(a[i])) print(a[i]), pc('; ';); endln;
}

signed main() {
#ifdef yyfLocal
    fileIn;
    fileOut;
#else  
#ifndef ONLINE_JUDGE   
    freopen(fn ".in", "r", stdin);
    freopen(fn ".out", "w", stdout);
#endif
#endif
    logs("main.exe");
    solution();
}

// Luogu Ranking Comparator
// Luogu Records Comparator
// JSB SDFZ
// D1T3 P1316