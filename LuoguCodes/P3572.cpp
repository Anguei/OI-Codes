// luogu-judger-enable-o2
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <deque>
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

namespace Baoli {
    const int N = 1000000 + 5;
    int n, q, a[N], dp[N];

    void solution() {
        n = read();
        rep(i, 1, n) a[i] = read();
        q = read();
        while (q--) {
            int k = read();
            // memset(dp, 0x3f, sizeof dp);
            std::fill(dp, dp + n + 1, 0x3f3f3f3f);
            dp[0] = dp[1] = 0;
            rep(i, k + 1, n) rep(j, i - k, i) dp[i] = std::min(dp[i], dp[j] + (a[j] <= a[i]));
            print(dp[n]), puts("");
        }
    }
}

namespace Zhengjie {
    struct Node {
        int pos, height, cost;
        Node() = default;
        Node (int pos, int height, int cost) : pos(pos), height(height), cost(cost) {}
    };

    const int N = 1000000 + 5;
    int n, q, a[N], dp[N];
    std::deque<Node> dq; // 存储坐标、高度、花费，花费单调递增，高度单调递减

    void solution() {
        n = read();
        rep(i, 1, n) a[i] = read();
        q = read();
        while (q--) {
            // std::fill(dp, dp + n + 1, 0);
            dq.clear();
            dq.push_back(Node(1, a[1], 0));

            int k = read();

            rep(i, 2, n) {
                bool can = true;
                while (!dq.empty() && dq.front().pos + k < i) dq.pop_front(); // 队列中的元素一定要合法（在 k 区间内）
                dp[i] = dq.front().cost + static_cast<bool>(dq.front().height <= a[i]); // 更新 dp 数组
                while (!dq.empty() && dp[i] <= dq.back().cost && can) {
                    while (!dq.empty() && dp[i] == dq.back().cost && can) { // 花费相同时，维护高度为单调递减
                        if (!dq.empty() && dq.back().height < a[i]) dq.pop_back();
                        if (!dq.empty() && (dq.back().cost < dp[i] || dq.back().height >= a[i])) can = false; // 如果已经满足单调就不要在 pop_back 了
                    }
                    if (can) dq.pop_back();
                }
                dq.push_back(Node(i, a[i], dp[i]));
            }

            print(dp[n]), puts("");
        }
    }
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
    // Baoli::solution();
    Zhengjie::solution();
}