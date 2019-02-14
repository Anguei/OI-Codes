// luogu-judger-enable-o2
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
#define fn "4872"
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

const int N = 100000 + 5, p = 100003;
int a[N], n, k, ans = 0, inv[N], need = 0, dp[N];
std::vector<int> factors[N];

void solution() {
    n = read(), k = read(); rep(i, 1, n) a[i] = read();
    inv[1] = 1; rep(i, 2, n) inv[i] = (p - p / i) * inv[p % i] % p;
    rep(i, 1, n) for (int j = i; j <= n; j += i) factors[j].push_back(i);
    per(i, n, 1) if (a[i]) { ++need; for (auto &j : factors[i]) a[j] ^= 1; }
    dp[n] = 1; per(i, n - 1, k + 1) dp[i] = (n + (n - i) * dp[i + 1]) * inv[i] % p; per(i, k, 1) dp[i] = 1;
    rep(i, 1, need) (ans += dp[i]) %= p; rep(i, 1, n) (ans *= i) %= p; println(ans);
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