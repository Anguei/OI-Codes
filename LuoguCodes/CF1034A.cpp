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
#pragma GCC optimize(3)
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

const int N = 15000005 + 5;
int n, max = 0, ans = 0, a[300000 + 5], bucket[N];
bool vis[N];

int gcd(int a, int b) {
    return !b ? a : gcd(b, a % b);
}

int getStart() {
    int res = a[1];
    rep(i, 2, n) res = gcd(a[i], res);
    return res;
}

void prime() {
    rep(i, 2, max) {
        if (!vis[i]) {
            int tmp = 0;
            for (int j = i; j <= max; j += i) tmp += bucket[j], vis[j] = true;
            ans = std::max(ans, tmp);
        }
    }
}

void solution() {
    n = read();
    rep(i, 1, n) a[i] = read();
    int start = getStart(); 
    rep(i, 1, n) ++bucket[a[i] / start], max = std::max(max, a[i] / start);
    prime();
    print(ans ? n - ans : -1), puts("");
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