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

struct Trie {
    int son[2], word;
    bool isEnd, haveSon;
};

const int N = 200000 * 32 + 5;
int n, cnt = 0;
Trie trie[N];

void insert(int x) {
    int u = 0;
    per(i, 32, 0) {
        bool id = (x >> i) & 1;
        if (!trie[u].son[id]) {
            trie[u].son[id] = ++cnt;
        }
        u = trie[u].son[id];
        ++trie[u].word;
    }
}

void erase(int x) {
    int u = 0;
    per(i, 32, 0) {
        bool id = (x >> i) & 1;
        u = trie[u].son[id];
        --trie[u].word;
    }
}

int query(int x) {
    int res = 0, u = 0;
    per(i, 32, 0) {
        bool id = ((x >> i) & 1) ^ 1;
        dbg(id);
        if (trie[u].son[id] && trie[trie[u].son[id]].word) logs("inc"), res += (1 << i), u = trie[u].son[id];
        else u = trie[u].son[id ^ 1];
    }
    return res;
}

void solution() {
    int q = read();
    insert(0);
    while (q--) {
        char opt; int x;
        std::cin >> opt >> x;
        if (opt == ';+';) insert(x);
        else if (opt == ';-';) erase(x);
        else if (opt == ';?';) print(query(x)), pc(';\n';);
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
    std::ios::sync_with_stdio(false); //std::cin.tie(nullptr); std::cout.tie(nullptr); std::clog.tie(nullptr);
    solution();
}