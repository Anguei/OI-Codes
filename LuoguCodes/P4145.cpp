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

#define lson (root << 1)
#define rson (root << 1 | 1)

const int N = 100000 + 5;
int n, Q, kase = 0, tree[N << 2];

void clear() { 
    memset(tree, 0, sizeof tree); 
}

void pushup(int root) {
    tree[root] = tree[lson] + tree[rson]; 
}

void build(int root, int l, int r) { 
    if (l == r) tree[root] = read(); 
    else { 
        int mid = (l + r) >> 1; 
        build(lson, l, mid); build(rson, mid + 1, r); 
        pushup(root); 
    }
}

int query(int root, int l, int r, int ql, int qr) {
    int res = 0;
    if (l > qr || r < ql)  return 0;
    if (l >= ql && r <= qr) res += tree[root];
    else {
        int mid = (l + r) >> 1;
        res += query(lson, l, mid, ql, qr) + query(rson, mid + 1, r, ql, qr);
    }
    return res;
}

void update(int root, int l, int r, int ul, int ur) {
    if (l > ur || r < ul || tree[root] <= r - l + 1) return;
    if (l == r) tree[root] = sqrt(tree[root]);
    else {
        int mid = (l + r) >> 1;
        update(lson, l, mid, ul, ur); update(rson, mid + 1, r, ul, ur);
        pushup(root);
    }
}

void answer() {
    Q = read(); dbg(Q);
    while (Q--) {
        int opt = read(), x = read(), y = read();
        if (x > y) std::swap(x, y);
        if (opt == 0) { // 开方
            update(1, 1, n, x, y);
        } else if (opt == 1) { // 求和
            print(query(1, 1, n, x, y)), pc(';\n';);
        }
    }
}

void solution() {
    clear();
    build(1, 1, n);
    answer();
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
    while (std::cin >> n) solution();
}