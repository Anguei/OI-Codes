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

const int N = 200000 + 5;
int n, s, ans = 0, a[N];

void solution() {
    n = read(), s = read();
    rep(i, 1, n) a[i] = read();
    std::sort(a + 1, a + n + 1);
    int mid = a[n / 2 + 1];
    if (mid > s) {
        ans += mid - s;
        per(i, n / 2, 1) if (a[i] > s) ans += a[i] - s; else break; //return print(ans), puts(""), 0;
    } else if (mid < s) {
        ans += s - mid;
        rep(i, n / 2 + 2, n) if (a[i] < s) ans += s - a[i]; else break; //return print(ans), puts(""), 0;
    } 
    print(ans), puts("");
}

signed main() {
#ifdef yyfLocal
    //fileIn;
    //fileOut;
#else  
#ifndef ONLINE_JUDGE   
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);
#endif
#endif
    solution();
}