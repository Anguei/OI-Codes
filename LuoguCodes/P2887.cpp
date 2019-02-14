// luogu-judger-enable-o2
// luogu-judger-enable-o2 
 // 用老婆插件提交 P2887
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
#define ll long long
#define int long long
#define pc(x) putchar(x)
#define fileIn freopen("testdata.in", "r", stdin)
#define fileOut freopen("testdata.out", "w", stdout)
#define rep(i, a, b) for (register int i = (a); i <= (b); ++i)
#define per(i, a, b) for (register int i = (b); i >= (a); --i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x" = " << (x) << std::endl
#else
#define dbg(x) x
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

const int C = 2500 + 5;
int pos = 1, ans = 0;
std::pair<int, int> cow[C], bottle[C];
std::priority_queue<int, std::vector<int>, std::greater<int>> pq; // 小的先出队

signed main() {
#ifdef yyfLocal
    fileIn;
#endif
    int c = read(), l = read();
    rep(i, 1, c) cow[i].first = read(), cow[i].second = read(); 
    rep(i, 1, l) bottle[i].first = read(), bottle[i].second = read();
    std::sort(cow + 1, cow + c + 1); 
    std::sort(bottle + 1, bottle + l + 1);
    rep(i, 1, l) {
        while (pos <= c && cow[pos].first <= bottle[i].first) // 阳光充足，且不被晒伤
            pq.push(cow[pos++].second); // 将最大值推进去
        while (!pq.empty() && bottle[i].second) {
            int x = pq.top(); pq.pop();
            if (x >= bottle[i].first) {
                ++ans;
                --bottle[i].second;
            }
        }
    }
    print(ans), puts("");
}