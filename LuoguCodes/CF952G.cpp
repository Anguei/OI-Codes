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
#else
#define dbg(x) x
#endif

void solution() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::string s;
    std::cin >> s;
    int n = s.size();
    std::cout << std::string(300, ';.';) << std::endl;
    for (const auto c : s) {
        std::cout << ".." + std::string(296, ';X';) + ".." << std::endl;
        std::cout << ".X"; rep(i, 0, c) std::cout << "X"; rep(i, c + 1, 297) std::cout << "."; std::cout << std::endl;
        std::cout << ".X" + std::string(298, ';.';) << std::endl;
        std::cout << std::string(300, ';.';) << std::endl;
        std::cout << ".."; rep(i, 0, c - 2) std::cout << "X."; rep(i, 0, 299 - (c << 1)) std::cout << "."; std::cout << std::endl;
        std::cout << std::string(300, ';.';) << std::endl;
        std::cout << ".X" + std::string(298, ';.';) << std::endl;
        std::cout << ".XX" + std::string(297, ';.';) << std::endl;
        std::cout << std::string(300, ';.';) << std::endl;
    }
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
    solution();
}