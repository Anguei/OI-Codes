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
#include <numeric>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define fn "task"
#define ll long long
//#define int long long
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
    int son[26];
    bool isEnd, haveSon, pos[97+26 + 5];
};

const int N = 500 * 100 + 5;
int n, cnt = 0;
Trie trie[N * 20];
std::vector<std::vector<std::string>> article;
std::map<std::string, std::vector<int>> map;
std::map<std::string, std::set<int>> set;

void insert(int x) {
    std::string s;
    std::cin >> s;
    int u = 0;
    for (const auto &i : s) {
        int id = i - 97;
        if (!trie[u].son[id]) trie[u].son[id] = ++cnt;
        u = trie[u].son[id];
    }
    trie[u].pos[x] = true;
}

void find() {
    std::string s;
    std::cin >> s;
    int u = 0;
    bool flag = true;
    for (const auto &i : s) {
        int id = i - 97;
        if (!trie[u].son[id]) {
            flag = false;
            break;
        }
        u = trie[u].son[id];
    }
    if (flag) {
        rep(i, 1, n) if (trie[u].pos[i]) print(i), pc('; ';); pc(';\n';);
    }
}

void solution() {
    n = read();
    rep(i, 1, n) {
        int nums = read();
        //std::vector<std::string> v;
        rep(j, 1, nums) {
            std::string s;
            std::cin >> s;
            //if (!set[s].count(i))
                map[s].push_back(i);
            //v.push_back(s);
            //insert(i);
        }
        //article.push_back(v);
    }
    int q = read();
    while (q--) {
        //find();
         int vis[200000] = { 0 };
        std::string s; std::cin >> s;
        for (const auto i : map[s]) if (!vis[i]) print(i), pc('; ';), vis[i] = 1; pc(';\n';);
    }
}

signed main() {
#ifdef yyfLocal
    fileIn;
    //fileOut;
#else  
#ifndef ONLINE_JUDGE   
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);
#endif
#endif
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    solution();
}