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

int tot = 0;
struct Matrix {
    int a[205][205];
    Matrix () { memset(a, 0x3f, sizeof a); }
    Matrix operator * (const Matrix &rhs) const {
        Matrix c;
        rep(k, 1, tot) rep(i, 1, tot) rep(j, 1, tot) c.a[i][j] = std::min(c.a[i][j], a[i][k] + rhs.a[k][j]);
        return c;
    }
} g, ans;

const int N = 1000 + 5;
int n, t, s, e, num[N * N];

void solution() {
    n = read() - 1, t = read(), s = read(), e = read();
    while (t--) {
        int w = read(), u = read(), v = read();
        if (!num[u]) num[u] = ++tot;
        if (!num[v]) num[v] = ++tot;
        g.a[num[u]][num[v]] = g.a[num[v]][num[u]] = w;
    }
    ans = g;
    while (n) {
        if (n & 1) ans = ans * g;
        g = g * g;
        n >>= 1;
    }
    print(ans.a[num[s]][num[e]]), puts("");
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