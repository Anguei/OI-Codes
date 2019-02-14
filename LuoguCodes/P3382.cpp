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

const int N = 13;
const double eps = 0.000001;
int n;
double l, r, a[15];

double sum(double x) {
    double res = 0.0f;
    rep(i, 0, n) res *= x, res += a[i];
    return res;
}

void solution() {
    std::cin >> n;
    std::cin >> l >> r;
    rep(i, 0, n) std::cin >> a[i];
    while (r - l > eps) {
        double mid = (l + r) / 2.0f;
        if (sum(mid - eps) > sum(mid)) r = mid;
        else l = mid;
    }
    std::cout << std::fixed << std::setprecision(5) << l << std::endl;
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