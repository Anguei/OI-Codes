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
// #define int long long
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

const int N = 100 + 5, M = 10 + 5, MAX = 63 + 1; // MAX 大小计算：每一行最多放四个（一种），也可以放三个（三种），也可以放两个（三种）……。1*2^4 + 3*2^3 + 3*2^2 + 3*2^1 + 3*2^0 = 55，取最接近 55 的 2 的幂 - 1 = 63
int n, m, idx = 0, ans = 0,
    line[N], // 每一行地图的状态
    set[MAX], // 所有合法方案的集合
    count[MAX], // 二进制表示下有多少个 1
    dp[N][MAX][MAX]; // dp[i][j][k] 表示第 i 行压缩后的状态为 j，第 i - 1 行压缩后状态为 k 时，第 i 行最多能够摆放多少炮兵
bool map[N][M];

bool ok(int x) {
    // 每一行当中，任意两个炮兵之间的距离至少为 2
    return !((x & (x << 1)) || (x & (x << 2)));
}

void input() {
    n = read(), m = read();
    rep(i, 1, n) rep(j, 1, m) {
        char ch; std::cin >> ch;
        map[i][j] = (ch == ';P';); // 对每一个可以放炮兵的位置进行标记
        if (ch == ';H';) line[i] |= (1 << (m - j)); // 预处理每一行地图的初始状态
    }
    // rep(i, 1, n) dbg(line[i]);
}

void init() {
    int max = (1 << m) - 1;
    rep(i, 0, max) {
        if (ok(i)) {
            set[idx] = i; // 新增一个合法状态
            count[idx++] = __builtin_popcount(i); // 这个状态一共可以放置多少炮兵
        }
    }
}

bool valid(int i, int x) {
    return !(line[i] & x);
}

void solveLine1() {
    dbg(idx);
    int i = 1; // 对第一行进行特殊处理
    rep(j, 0, idx - 1) if (valid(i, set[j])) ans = std::max(ans, (dp[i][j][0] = count[j]));
}

void solveLineAfter() {
    // 枚举方案的时候，只需要在已经预处理好的 set 数组中枚举合法的方案，所以这里 j、k 的循环边界时 idx - 1
    rep(i, 2, n) rep(j, 0, idx - 1) if (valid(i, set[j])) { // 第 i 行是否可以用方案 set[j]
        rep(k, 0, idx - 1) if (valid(i - 1, set[k]) && (set[j] & set[k]) == 0) { // 前一行拥有的合法状态不能与当前行相同
            int max = 0; // 前面的最优值
            rep(l, 0, idx - 1) if (valid(i - 2, set[l]) && dp[i - 1][k][l] != -1 && (set[l] & set[j]) == 0) { // 再枚举一次第 i - 2 行
                max = std::max(max, dp[i - 1][k][l]);
            }
            dp[i][j][k] = std::max(dp[i][j][k], max + count[j]); // 当前最优值 = 之前最优值 + 当前炮兵数
            if (i == n) ans = std::max(ans, dp[i][j][k]);
        }
    }
}

void output() {
    print(ans), pc(';\n';);
}

void solution() {
    input();
    init();
    solveLine1();
    solveLineAfter();
    output();
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
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    solution();
}

