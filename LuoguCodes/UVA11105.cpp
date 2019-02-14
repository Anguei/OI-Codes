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
#define ll long long
#define int long long
#define pc(x) putchar(x)
#define fileIn freopen("testdata.in", "r", stdin)
#define fileOut freopen("testdata.out", "w", stdout)
#define rep(i, a, b) for (register int i = (a); i <= (b); ++i)
#define per(i, a, b) for (register int i = (b); i >= (a); --i)
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

const int N = 1000000 + 5;
int cnt = 0;
bool h[N], hs[N];
int ans[N];

void init() {
    h[1] = false;
    for (int i = 5; i < N; i += 4) if (h[i]) continue; else for (int j = i * 5; j < N; j += i * 4) h[j] = true;
    for (int i = 5; i < N; i += 4) for (int j = 5; j < N; j += 4) if (i * j > N) break; else if (!h[i] && !h[j]) hs[i * j] = true;
    for (int i = 5; i < N; ++i) ans[i] = (hs[i] ? ++cnt : cnt);
}

signed main() {
#ifdef yyfLocal
    fileIn;
#endif
    init();
    int n; while (std::cin >> n && n) print(n), pc('; ';), print(ans[n]), puts("");
}