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

int a[30005], u[30005];

void solution() {
    int m, n;
    m = read(), n = read();
    memset(a, 0, sizeof a); memset(u, 0, sizeof u); 
    for (int i = 1; i <= m; ++i) a[i] = read();
    for (int i = 1; i <= n; ++i) u[i] = read();
    std::vector<int> nums;
    int now = 0, p = 1;
    std::priority_queue<int, std::vector<int>, std::greater<int>> q_ans; // 前i小的
    std::priority_queue<int, std::vector<int>> q_heap;
    for (int i = 1; i <= m; ++i) {
        q_heap.push(a[i]);
        if (now < q_heap.size()) {
            q_ans.push(q_heap.top());
            q_heap.pop();
        }
        while (u[p] == i) {
            ++now;
            std::cout << q_ans.top() << std::endl;
            q_heap.push(q_ans.top());
            q_ans.pop();
            ++p;
        }
    }
}

signed main() {
#ifdef yyfLocal
    fileIn;
    fileOut;
#else  
#ifndef ONLINE_JUDGE   
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);
#endif
#endif
    logs("main.exe");
    int T = read(); rep(i, 0, T - 1) { if (i) std::cout << std::endl; solution(); }
}