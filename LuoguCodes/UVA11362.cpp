// -o %s %s.* -O2 -std=c++17 -Wl,--stack=8129334 -D yyfLemon
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
#pragma GCC optimize(3)
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

struct Node {
	int son[10];
	int cnt;
	bool isend, haveson;
};

const int N = 100000 + 5;
int n, tot = 0;
bool flag = false;
Node words[N];

void clear() {
	memset(words, 0, sizeof words);
	flag = false;
	tot = 0;
}

void insert(const std::string &s) {
	int u = 0;
	for (int i = 0; i < s.size(); ++i) {
		int id = s[i] - 48;
		if (!words[u].son[id])  {
			words[u].son[id] = ++tot;
			words[u].haveson = true;
		}
		u = words[u].son[id];
	}
	words[u].isend = true;
}

void solution() {
	clear();
	n = read();
	std::vector<std::string> v;
	rep(i, 1, n) {
		std::string s;
		std::cin >> s;
		v.push_back(s);
	}
	for (int i = 0; i < n; ++i) {
		insert(v[i]);
	}
	rep(i, 1, tot) if (words[i].isend && words[i].haveson) {
		std::cout << "NO\n";
		return;
	}
	std::cout << "YES\n";
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
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int T = read(); while(T--) solution();
}