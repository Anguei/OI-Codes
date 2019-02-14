// luogu-judger-enable-o2
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define fn "3668"
#define ll long long
#define int long long
#define pc(x) std::cout.put(x)
#define endln std::cout.put(';\n';)
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
    int res = 0, flag = 1; char ch = std::cin.get();
    while (!isdigit(ch)) { if (ch == ';-';) flag = -1; ch = std::cin.get(); }
    while (isdigit(ch)) res = res * 10 + ch - 48, ch = std::cin.get();
    return res * flag;
}

void print(int x) {
    if (x < 0) std::cout.put(';-';), x = -x;
    if (x > 9) print(x / 10);
    std::cout.put(x % 10 + 48);
}

void solution() {
    int n = read(), m = read(), num; std::string opt; std::bitset<30> a, b(1073741823), c;
    while (n--) { std::cin >> opt >> num; if (opt.front() == ';A';) a &= num, b &= num; else if (opt.front() == ';O';) a |= num, b |= num; else if (opt.front() == ';X';) a ^= num, b ^= num; }
    rep(i, 0, 30 - 1) if (a[i] | (b[i] && c.to_ullong() < m)) c[i] = 1; println(c.to_ullong());    
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
#if __cplusplus >= 201103L
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); solution();
#else
    std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0); solution();
#endif
}