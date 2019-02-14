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
#define fn "2609"
#define ll long long
// #define int long long
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

const int N = 100000 + 5, p = 99999997;
int n, a[N], b[N], c[N], d[N], q[N], bit[N], ans = 0;

void add(int pos, int val) { while (pos <= n) { bit[pos] += val; pos += 1 << __builtin_ctz(pos); } }
int query(int pos) { int res = 0; while (pos > 0) { dbg(pos); res += bit[pos], pos -= 1 << __builtin_ctz(pos); } return res; }

void solution() {
    dbg(__builtin_ctz(3)); // dbg(builtin_ctz(3));
    logs("solution():"); n = read(); rep(i, 1, n) a[i] = read(), c[i] = i; rep(i, 1, n) b[i] = read(), d[i] = i;
    logs("read"); std::sort(c + 1, c + n + 1, [](int i, int j) { return a[i] < a[j]; }); std::sort(d + 1, d + n + 1, [](int i, int j) { return b[i] < b[j]; });
    logs("sorted"); rep(i, 1, n) q[c[i]] = d[i]; per(i, n, 1) (ans += query(q[i] - 1)) %= p, logs("queryed"), add(q[i], 1); println(ans);
}

signed main() {
#ifdef yyfLemon
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);
#else
#ifndef ONLINE_JUDGE
    fileIn;
    // filtOut
#endif
#endif
    // logs("2609.exe");
    solution();
}