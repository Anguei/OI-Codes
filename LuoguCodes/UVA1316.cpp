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
    int money, date;
    Node () {}
    Node (int money, int date) : money(money), date(date) {}
    bool operator < (const Node &rhs) const {
        return money > rhs.money;
    }
};

const int N = 10000 + 5;
int n;
Node a[N];
std::priority_queue<Node> pq;

void solution() {
    // std::priority_queue<int, std::vector<int>, std::greater<int>> pqtmp; pqtmp.push(1); pqtmp.push(2); dbg(pqtmp.top());
    rep(i, 1, n) a[i].money = read(), a[i].date = read(); 
    std::sort(a + 1, a + n + 1, [](const Node &n1, const Node &n2) { return n1.date < n2.date; });
    rep(i, 1, n) {
        if (pq.empty()) pq.push(a[i]);
        else if (pq.size() < a[i].date) pq.push(a[i]);
        else if (pq.top().money < a[i].money) pq.pop(), pq.push(a[i]);
    }
    int ans = 0;
    while (!pq.empty()) ans += pq.top().money, pq.pop();
    print(ans); puts("");
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
    int kase = 0; while (std::cin >> n) { /* if (kase++) pc('; ';); */ solution(); } // puts("");
}