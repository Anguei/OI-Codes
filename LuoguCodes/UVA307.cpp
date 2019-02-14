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
#include <functional>
#define fn "task"
#define ll long long
#define int long long
#define pc(x) std::cout.put(x)
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
    int res = 0, flag = 1; char ch = std::cin.get();
    while (!isdigit(ch)) { if (ch == ';-';) flag = -1; ch = std::cin.get(); }
    while (isdigit(ch)) res = res * 10 + ch - 48, ch = std::cin.get();
    return res * flag;
}

void print(int x) {
    if (x < 0) std::cout.put(';-';), x = -x;
    if (x > 9) print(x / 10);
    std::cout.put(x % 10 + 48);
}

const int N = 64 + 5;
int n, sum, max, cnt, len, a[N];
bool vis[N];

bool dfs(int now, int nowLen, int lastStick) {
    // std::clog << now << " " << nowLen << " " << lastStick << std::endl;
    if (now > cnt) return true; // 全都拼好了
    if (nowLen == len) return dfs(now + 1, 0, 1);
    int fail = -1; // 上一次拼接失败是哪个长度
    rep(i, lastStick, n) if (!vis[i] && nowLen + a[i] <= len && fail != a[i]) {
        vis[i] = true;
        if (dfs(now, nowLen + a[i], i + 1)) return true;
        fail = a[i];
        vis[i] = false;
        if (nowLen == 0 || nowLen + a[i] == len) return false;
    }
    return false;
}

void solution() {
    sum = max = cnt = len = 0;
    rep(i, 1, n) a[i] = read(), sum += a[i], max = std::max(max, a[i]);
    std::sort(a + 1, a + n + 1, std::greater<int>());
    for (len = max; len <= sum; ++len) if (sum % len == 0) {
        memset(vis, false, sizeof vis); // 这里是不是不需要清空啊？
        cnt = sum / len;
        if (dfs(1, 0, 1)) { print(len), pc(';\n';); return; }
    }
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
    while (std::cin >> n && n) solution();
    // 为什么命令行方向上 + 回车出 6，是不是智障设计？
}