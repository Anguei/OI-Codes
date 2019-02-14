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

struct Node {
    int x, y, z;
    Node() {}
    Node(int x, int y, int z) : x(x), y(y), z(z) {}
    bool operator<(const Node &rhs) const { return z < rhs.z; }
};

const int N = 50000 + 5; 
int n; double ans = 0; Node a[N];
#define sqr(x) ((x) * (x))

void solution() {
    n = read(); rep(i, 1, n) { int x = read(), y = read(), z = read(); a[i] = Node(x, y, z); } std::sort(a + 1, a + n + 1);
    rep(i, 2, n) ans += static_cast<double>(sqrt(sqr(a[i].x - a[i - 1].x) + sqr(a[i].y - a[i - 1].y) + sqr(a[i].z - a[i - 1].z))), dbg(ans);
    std::cout << std::fixed << std::setprecision(3) << ans << std::endl;
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