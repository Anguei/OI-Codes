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
#include <iostream>
#include <algorithm>
#define ll long long
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x" = " << (x) << std::endl
#else
#define dbg(x) x
#endif

int read() {
    int res = 0, flag = 1; char ch = std::cin.get();
    while (!isdigit(ch)) { if (ch == ';-';) flag = -1; ch = std::cin.get(); }
    while (isdigit(ch)) res = res * 10 + ch - 48, ch = std::cin.get();
    return res * flag;
}

const int N = 35;
int n;
int map[N][N];

int solve() {
    rep(i, 1, n - 1) rep(j, i + 1, n) map[i][j] = map[j][i] = read();
    int ans = 0;
    rep(i, 3, n) {
        int tmp = 0x3f3f3f3f3f;
        rep(j, 2, i - 1) tmp = std::min(tmp, map[1][i] - ((map[1][i] + map[1][j] - map[i][j]) >> 1));
        ans += tmp;
    }
    return ans + map[1][2];
}

signed main() {
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    while (std::cin >> n && n) std::cout << solve() << std::endl;
#ifdef yyfLocal
    std::cin.get(); std::cin.get();
#endif
}