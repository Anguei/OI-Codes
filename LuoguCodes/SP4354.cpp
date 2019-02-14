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

const int N = 100000 + 5, p = 99991;
int n, tot = 0, snow[N][6], head[N], next[N];

int H(int *a) {
    int sum = 0, mul = 1;
    rep(i, 0, 5) {
        sum = (sum + a[i])  % p;
        mul = static_cast<long long>(mul) * a[i] % p;
    }
    return (sum + mul) % p;
}

bool equal(const int *a, const int *b) {
    rep(i, 0, 5) rep(j, 0, 5) {
        bool eq = true;
        rep(k, 0, 5) if (a[(i + k) % 6] != b[(j + k) % 6]) eq = false;
        if (eq) return true;
        eq = true;
        rep(k, 0, 5) if (a[(i + k) % 6] != b[(j - k + 6) % 6]) eq = false;
        if (eq) return true;
    }
    return false;
}

void insert(int *a) {
    int val = H(a);
    for (int i = head[val]; i; i = next[i]) 
        if (equal(snow[i], a)) { puts("Twin snowflakes found."); exit(0); }
    memcpy(snow[++tot], a, 6 * sizeof(int));
    next[tot] = head[val]; head[val] = tot;
}

void solution() {
    n = read();
    while (n--) {
        int a[10];
        rep(i, 0, 5) a[i] = read();
        insert(a);
    }
    puts("No two snowflakes are alike.");
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