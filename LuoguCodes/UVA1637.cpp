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
#define fn "2875"
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

std::string card[9][4];
std::vector<int> cnt;
std::map<std::vector<int>, double> map;

bool newData() { rep(i, 0, 8) rep(j, 0, 3) if (!(std::cin >> card[i][j])) return false; return true; }

double dp(int c) {
    if (!c) return 1.0;
    if (map.count(cnt)) return map[cnt];
    double sum = 0.0; int tot = 0;
    rep(i, 0, 8) if (cnt[i]) rep(j, i + 1, 8) if (cnt[j]) if (card[i][cnt[i] - 1][0] == card[j][cnt[j] - 1][0]) {
        ++tot; --cnt[i]; --cnt[j]; sum += dp(c - 2); ++cnt[i]; ++cnt[j];
    }
    return !tot ? map[cnt] = 0 : map[cnt] = sum / tot;
}

void solution() {
    cnt = std::vector<int>(9, 4); map.clear(); std::cout << std::fixed << std::setprecision(6) << dp(36) << std::endl;;
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
    while (newData()) solution();
}