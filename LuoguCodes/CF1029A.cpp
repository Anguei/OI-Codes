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

void solution() {
    int n = read(), m = read();
    std::string t; std::cin >> t;
    /*std::set<char> set;
    for (auto i : t) set.insert(i);
    if (set.size() == 1) {
        std::cout << std::string(k, *set.begin()) << std::endl;
        exit(0);
    } */
    /*int len = 0;
    for (int i = 0; i < n / 2 + 1; ++i) if (t[i] == t[n - i - 1]) ++len;
    dbg(len);
    std::cout << t; for (int i = 1; i < k; ++i) std::cout << t.substr(len == 0 ? 0 : len - 1);
    std::cout << std::endl;*/
    int i = 0, j = n - 1, jj = j;
    while (i < t.size() && j) {
        bool flag = false;
        rep(l, 0, i) if (t[l] != t[n - 1 - i + l]) flag = true;
        ++i, --j;
        if (flag) continue;
        jj = j;
    }
    rep(k, 1, m) rep(l, 0, jj) pc(t[l]);
    rep(l, jj + 1, n - 1) pc(t[l]);
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
// Fark Judging * 3 