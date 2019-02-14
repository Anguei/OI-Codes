// luogu-judger-enable-o2
#include <ctime>
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

const int N = 10 + 5;
long double x[N], y[N];

void solution() {
#define sqr(x) ((x) * (x))
    int n, l; std::cin >> n >> l;
    rep(i, 1, n) std::cin >> x[i] >> y[i];
    rep(kase, 0, static_cast<int>(1e7 + 0.5)) {
        long double nx = rand(), ny = rand();
        while (nx > l) nx /= 10; while (ny > l) ny /= 10;
        rep(i, 1, n) if (sqrt(sqr(nx - x[i]) + sqr(ny - y[i])) < sqrt(sqr(l / n))) { goto nextLoop; }
        std::cout << std::fixed << std::setprecision(3) << nx << " " << ny << std::endl; return;
    nextLoop: ;
    }
    std::cout << "GG" << std::endl;
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
    srand(19260817); // srand(rand());
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    solution();
}