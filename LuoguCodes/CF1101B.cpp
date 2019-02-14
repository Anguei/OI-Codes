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

int find(const std::string &s, int l, int r, char target) { rep(i, l, r - 1) if (s[i] == target) return i; return -1; }
int rfind(const std::string &s, int l, int r, char target) { per(i, r - 1, l) if (s[i] == target) return i; return -1; }

void solution() {
    std::string s; std::cin >> s;
    int p1 = find(s, 0, s.size(), ';[';); if (p1 == -1) { println(-1); return; } dbg(p1);
    int p2 = find(s, p1 + 1, s.size(), ';:';); if (p2 == -1) { println(-1); return; } dbg(p2); 
    int p3 = rfind(s, p2, s.size(), ';]';);if (p3 == -1) { println(-1); return; } dbg(p3); 
    int p4 = rfind(s, p2 + 1, p3, ';:';); if (p4 == -1) { println(-1); return; } dbg(p4); 
    int ans = 0; for (int i = p2 + 1; i < p4; ++i) ans += s[i] == ';|';; println(ans + 4);
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

// Luogu Ranking Comparator
// Luogu Records Comparator