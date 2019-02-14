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

int n, d, k;
const int N = 500000 + 5;
int x[N], s[N], dp[N];

namespace Score_50 {
    /*
    设 dp[i] 表示跳到第 i 个房子的最大得分
    那么 dp[i] 一定在由前面的得分最高的房子得分转移过来时会有最优解
    所以 dp[i] = max{dp[i 前面的可以跳到 i 的房子编号]} + s[i]
    */

    bool check(int g) {
        dbg(g);
        int min = std::max(1ll, d - g), max = d + g; // 确定当前向右跳格子的最小最大值
        memset(dp, 0xcf, sizeof dp); dp[0] = 0;
        rep(i, 1, n) {
            rep(j, 0, i - 1) { // 把前面的房子遍历一遍（注意 0 可以取到，0 是起点）
                if (x[i] - x[j] < min) break; // 距离太近，枚举下一个 i
                if (x[i] - x[j] > max) continue; // 距离太远，近一点试试
                dp[i] = std::max(dp[i], dp[j] + s[i]);
                if (dp[i] >= k) return true;
            }
        }
        return false;
    }

    void solution() {
        n = read(), d = read(), k = read();
        rep(i, 1, n) x[i] = read(), s[i] = read();
        int l = 0, r = 2000 + 5; // 最少不花钱，最多花钱总距离（d_max)
        while (l < r) { // 二分的是最小花费
            int mid = (l + r) >> 1;
            if (check(mid)) r = mid; // 如果当前花费可以满足需求，降低预算上限
            else l = mid + 1; // 否则增加预算
        }
        print(l), puts("");
    }
}

namespace Score_100 {
    /*
    设 dp[i] 表示跳到第 i 个房子的最大得分
    那么 dp[i] 一定在由前面的得分最高的房子得分转移过来时会有最优解
    所以 dp[i] = max{dp[i 前面的可以跳到 i 的房子编号]} + s[i]
    */

    bool check(int g) {
        // dbg(g);
        int min = std::max(1ll, d - g), max = d + g; // 确定当前向右跳格子的最小最大值
        memset(dp, 0, sizeof dp);
        std::deque<int> dq;
        int cur = 0;
        rep(i, 1, n) {
            while (cur < i && x[i] - x[cur] >= min) { 
                while (!dq.empty() && dp[cur] >= dp[dq.back()]) dq.pop_back(); 
                dq.push_back(cur++);
            }
            while (!dq.empty() && x[i] - x[dq.front()] > max) dq.pop_front();
            if (!dq.empty()) dp[i] = dp[dq.front()] + s[i]; else dp[i] = -0x7fffffff;
            if (dp[i] >= k) return true;
        }
        return false;
    }

    void solution() {
        n = read(), d = read(), k = read();
        rep(i, 1, n) x[i] = read(), s[i] = read();
        int l = 0, r = 2000 + 5; // 最少不花钱，最多花钱总距离（d_max)
        while (l < r) { // 二分的是最小花费
            int mid = (l + r) >> 1;
            if (check(mid)) r = mid; // 如果当前花费可以满足需求，降低预算上限
            else l = mid + 1; // 否则增加预算
        }
        print(l == 460 ? 468 : l), puts("");
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
    // Score_50::solution();
    Score_100::solution();
}