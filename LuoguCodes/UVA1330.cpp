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

const int N = 1000 + 5;
int n, m, sum[N][N];

void init() {
    n = read(), m = read();
    rep(i, 1, n) rep(j, 1, m) {
        char ch; std::cin >> ch;
        sum[i][j] = ch == ';R'; ? 0 : sum[i - 1][j] + 1;
    }
}

void onot() {
    int ans = 0;
    rep(i, 1, n) {
        sum[i][m + 1] = -1;
        std::stack<int> stk;
        rep(j, 1, m + 1) {
            if (stk.empty() || sum[i][j] > sum[i][stk.top()]) stk.push(j);
            else if (sum[i][j] < sum[i][stk.top()]) {
                int pos = 0;
                while (!stk.empty() && sum[i][j] < sum[i][stk.top()]) {
                    ans = std::max(ans, (j - stk.top()) * sum[i][stk.top()]);
                    pos = stk.top(); stk.pop();
                }
                stk.push(pos); sum[i][pos] = sum[i][j];
            }
        }
    }
    print(ans * 3), puts("");
}

void solution() {
    init();
    onot();
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
    int T = read(); while (T--) solution();
}