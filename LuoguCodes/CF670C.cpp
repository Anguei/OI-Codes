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

const int N = 200000 + 5, M = 200000 +5;
int n, m, tot, tmp, ans, maxB, maxC, a[N], b[M], c[M], ansB[N + (M << 1)], ansC[N + (M << 1)];
std::vector<int> v;

void solution() {
#define hashA (std::lower_bound(v.begin(), v.end(), a[i]) - v.begin())
#define hashB (std::lower_bound(v.begin(), v.end(), b[i]) - v.begin())
#define hashC (std::lower_bound(v.begin(), v.end(), c[i]) - v.begin())
    n = read(); rep(i, 1, n) v.push_back(a[i] = read());
    m = read(); rep(i, 1, m) v.push_back(b[i] = read()); rep(i, 1, m) v.push_back(c[i] = read());
    std::sort(v.begin(), v.end()); tot = std::unique(v.begin(), v.end()) - v.begin();
    rep(i, 1, n) ++ansB[hashA], ++ansC[hashA];
    rep(i, 1, m) if (i == 1 || ansB[hashB] > maxB || (ansB[hashB] == maxB && ansC[hashC] > maxC)) ans = i, maxB = ansB[hashB], maxC = ansC[hashC];
    print(ans), puts("");
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
    solution();
}
