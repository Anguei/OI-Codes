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

struct Node {
    int pos, val;
    Node () = default;
    Node(int pos, int val) : pos(pos), val(val) {}
};

const int N = 3000000 + 5;
int n, k, last = 1, ans = 0, a[N];
std::deque<Node> min, max;

void solution() {
    k = read(), n = read();
    rep(i, 1, n) a[i] = read();
    rep(i, 1, n) {
        while (!max.empty() && a[i] >= max.back().val) max.pop_back(); max.push_back(Node(i, a[i]));
        while (!min.empty() && a[i] <= min.back().val) min.pop_back(); min.push_back(Node(i, a[i]));
        while (max.front().val - min.front().val > k) if (max.front().pos > min.front().pos) last = min.front().pos + 1, min.pop_front(); else last = max.front().pos + 1, max.pop_front();
        ans = std::max(ans, i - last + 1);
    }
    print(ans), puts("");
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