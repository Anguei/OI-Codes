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

void solution() {
    int n; std::cin >> n;
    std::cout << "0 1" << std::endl;
    std::string s, t; std::cin >> s;
    int l = 1, r = 1e9 - 1;
    rep(i, 2, n) {
        int mid = (l + r) >> 1;
        std::cout << mid << " 1" << std::endl;
        std::cin >> t;
        if (s == t) l = mid + 1;
        else r = mid - 1;
    }
    std::cout << l - 1 << " 0 " << r + 1 << " 2" << std::endl;
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
    std::ios::sync_with_stdio(false); std::cout.tie(nullptr); std::cin.tie(nullptr);
    solution();
}