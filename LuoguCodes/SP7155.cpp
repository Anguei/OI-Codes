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
std::string s[3];
int ans = -1ull / 2, c = 29;

bool contains(const std::string &a, const std::string &b) {
    int n = a.size(), m = b.size();
    unsigned int hash1 = 0, hash2 = 0, x = 1;
    if (!n || !m || n < m) return false;
    rep(i, 0, m - 1) hash2 = hash2 + x * (b[i] - 96), x *= c;
    per(i, n - 1, 0) {
        hash1 = c * hash1 + a[i] - 96;
        if (i + m < n) hash1 -= x * (a[i + m] - 96);
        if (i + m <= n && hash1 == hash2) return true;
    }
    return false;
}

std::string join(const std::string &a, const std::string &b) {
    int n = a.size(), m = b.size(), k = std::min(n, m);
    unsigned int hash1 = 0, hash2 = 0, x = 1, l = 0;
    rep(i, 0, k - 1) {
        hash1 = c * hash1 + (a[n - 1 - i] - 96), hash2 = hash2 + x * (b[i] - 96), x *= c;
        if (hash1 == hash2) l = i + 1;
    }
    return a + (b.substr(l));
}

void solution() {
    ans = -1ull / 2, c = 29;
    rep(i, 0, 2) rep(j, 0, 2) if (i != j && contains(s[i], s[j])) s[j] = "";
    ans = std::min(static_cast<std::size_t>(ans), join(join(s[0], s[1]), s[2]).size());
    ans = std::min(static_cast<std::size_t>(ans), join(join(s[0], s[2]), s[1]).size());
    ans = std::min(static_cast<std::size_t>(ans), join(join(s[1], s[0]), s[2]).size());
    ans = std::min(static_cast<std::size_t>(ans), join(join(s[1], s[2]), s[0]).size());
    ans = std::min(static_cast<std::size_t>(ans), join(join(s[2], s[0]), s[1]).size());
    ans = std::min(static_cast<std::size_t>(ans), join(join(s[2], s[1]), s[0]).size());
    print(ans), puts("");
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
    while (std::cin >> s[0] >> s[1] >> s[2]) solution();
}