// luogu-judger-enable-o2
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
#include <iomanip>
#include <iostream>
#include <algorithm>
#define fn "testdata"
#define ll long long
#define int long long
#define pc(x) std::cout.put(x)
#define endln std::cout.put(';\n';)
#define println(x) print(x), endln
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

const int N = 100000 + 5;
std::map<std::string, int> map;
int n, a[N], tmp[N], ans = 0;

void msort(int l, int r) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    msort(l, mid); msort(mid + 1, r);
    int i = l, j = mid + 1, pos = l;
    while (i <= mid && j <= r) {
        if (a[i] > a[j]) {
            tmp[pos++] = a[j++];
            ans += mid - i + 1;
        } else { 
            tmp[pos++] = a[i++];
        }
    }
    while (i <= mid) tmp[pos++] = a[i++];
    while (j <= r) tmp[pos++] = a[j++];
    rep(i, l, r) a[i] = tmp[i];
}

void solution() {
    n = read();
    rep(i, 1, n) { std::string tmp; std::cin >> tmp; map[tmp] = i; }
    rep(i, 1, n) { std::string tmp; std::cin >> tmp; a[i] = map[tmp]; }
    msort(1, n); println(ans);
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
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); solution();
}