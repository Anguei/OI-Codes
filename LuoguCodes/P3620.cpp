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
#define fn "1150"
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

const int N = 100000 + 5;
int n, k, pos = 0, ans = 0, a[N], next[N], prev[N], list[N], map[N];

void up(int pos) {
    while (pos > 1) {
        if (a[list[pos]] < a[list[pos >> 1]]) {
            std::swap(list[pos], list[pos >> 1]); std::swap(map[list[pos]], map[list[pos >> 1]]);
            pos >>= 1;
        } else break;
    }
}

void insert(int x) {
    list[++pos] = x; map[x] = pos; up(pos);
}

void down(int l, int r) {
	int mid = l << 1;
	while (mid <= r) {
		if (mid < r && a[list[mid]] > a[list[mid + 1]]) ++mid;
		if (a[list[l]] > a[list[mid]]) {
			std::swap(list[l], list[mid]); std::swap(map[list[l]], map[list[mid]]);
			l = mid, mid = l << 1;
		} else break;
	}
}

void erase(int x) {
    list[map[x]] = list[pos];
	map[list[pos]] = map[x];
	up(map[x]), down(map[x], --pos);
}

void solution() {
    n = read(), k = read();
    rep(i, 1, n) a[i] = read();
    rep(i, 1, n - 1) a[i] = a[i + 1] - a[i], next[i] = i + 1, prev[i + 1] = i, insert(i);
    while (k--) {
        int x = list[1]; ans += a[x];
        if (!prev[x] && next[x] == n) break;
        if (!prev[x]) erase(x), erase(next[x]), prev[next[next[x]]] = 0;
        else if (next[x] == n) erase(x), erase(prev[x]), next[prev[prev[x]]] = n;
        else {
            a[x] = a[prev[x]] + a[next[x]] - a[x]; erase(x), erase(prev[x]), erase(next[x]); insert(x);
			prev[x] = prev[prev[x]]; next[prev[x]] = x; next[x] = next[next[x]]; prev[next[x]] = x;
        }
    }
    print(ans), puts("");
}

signed main() {
#ifdef yyfLocal
    fileIn;
    // fileOut;
#endif
    logs("main.exe"); solution();
}