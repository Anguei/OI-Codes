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
struct Data {
    int id, a, c;
    Data(){}
    Data(int id, int a, int c) : id(id), a(a), c(c) {}
    bool operator<(const Data &rhs) const {
        return c < rhs.c;
    }
} x[N];

int n, m, pos = 1;
std::map<int, int> map;

void solution() {
    n = read(), m = read();
    rep(i, 1, n) x[i].a = read(), x[i].id = i;
    rep(i, 1, n) x[i].c = read();
    std::sort(x + 1, x + n + 1);
    rep(i, 1, n) map[x[i].id] = i;
    while (m--) {
        int t = read(), d = read(), ans = 0; t = map[t];
        if (x[t].a >= d) ans = d * x[t].c, x[t].a -= d, d = 0;
        else {
            ans = x[t].a * x[t].c, d -= x[t].a, x[t].a = 0;
            while (pos <= n && d) {
                int now = std::min(d, x[pos].a);
                d -= now, x[pos].a -= now;
                ans += now * x[pos].c;
                if (!x[pos].a) ++pos;
            }
        }
        println(d ? 0 : ans);
    }
}

signed main() {
#ifdef yyfLocal
    fileIn;
    // fileOut;
#else  
#ifndef ONLINE_JUDGE   
    freopen(fn ".in", "r", stdin);
    freopen(fn ".out", "w", stdout);
#endif
#endif
    logs("main.exe");
    solution();
}