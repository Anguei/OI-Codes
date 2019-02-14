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

const int N = 2000 + 5;
int n, m, x, ans = 0, a[N], b[N];

void solution() {
    n = read(), m = read();
    rep(i, 1, n) a[i] = read(), a[i] = a[i - 1] + a[i];
    rep(i, 1, m) b[i] = read(), b[i] = b[i - 1] + b[i];
    x = read();
    rep(i, 1, n) {
        int pos = 1;
        rep(j, 2, n - i + 1) if (a[j + i - 1] - a[j - 1] < a[pos + i - 1] - a[pos - 1]) pos = j;
        int tmp = 0, s = a[pos + i - 1] - a[pos - 1];
        rep(j, 1, m) {
            while (tmp < m && s * (b[tmp + 1] - b[j - 1]) <= x) ++tmp;
            ans = std::max(ans, i * (tmp - j + 1));
        }
    }
    print(ans), puts("");
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
    solution();
}