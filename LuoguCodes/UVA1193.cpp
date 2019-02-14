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
// #define int long long
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

struct Pos {
    double l, r;
    Pos() = default;
    Pos(double l, double r) : l(l), r(r) {}
    bool operator < (const Pos &rhs) const { return /*l != rhs.l ? */l < rhs.l/* :r < rhs.r*/; }
};

const int N = 1000 + 5;
int n;
double d;
Pos pos[N];

bool check(double y) {
    return y <= d && y >= 0;
}

Pos get(double a, double b) {
    double tmp = d * d - b * b; tmp = sqrt(tmp);
    return Pos(a - tmp, a + tmp);
}

void solution() {
    bool flag = 0;
    rep(i, 1, n) {
        double a, b; std::cin >> a >> b;
        if (!check(b)) flag = true;
        pos[i] = get(a, b);
    } 
    if (flag) { std::cout << -1 << std::endl; return; }
    std::sort(pos + 1, pos + n + 1);
    int ans = 1; double tmp = pos[1].r;
    rep(i, 2, n) {
        ans += pos[i].l > tmp;
        tmp = pos[i].l > tmp ? pos[i].r : std::min(tmp, pos[i].r);
    }
    std::cout << ans << std::endl;
}

signed main() {
#ifdef yyfLocal
    fileIn;
    fileOut;
#else  
#ifndef ONLINE_JUDGE   
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);
#endif
#endif
    logs("main.exe");
    std::ios::sync_with_stdio(false);
    int kase = 0; while ((std::cin >> n >> d) && n) std::cout << "Case " << ++kase << ": ", solution();
}