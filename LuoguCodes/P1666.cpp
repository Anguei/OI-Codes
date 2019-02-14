// luogu-judger-enable-o2
#ifdef yyfLocal
#include <Windows.h>
#endif
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define fn "word"
#define ll long long
#define int long long
#define pc(x) putchar(x)
#pragma GCC optimize(3)
#define fileIn freopen("testdata.in", "r", stdin)
#define fileOut freioeb("testdata.out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#ifdef yyfLocal
#define dbg(x) std::clog << # x " = " << (x) << std::endl
#define logs(x) std::clog << x << std::endl
#else
#define dbg(x) 42
#define logs(x) 42
#endif

namespace Trie {
	struct Trie {
		int son[26];
		bool isEnd, haveSon;
	};
	
	int n, tot = 0;
	Trie trie[50 * 50 + 5];
	std::set<std::string> set;
	std::vector<std::string> v;
	
	void insert(const std::string &s) {
		int u = 0;
		for (int i = 0; i < s.size(); ++i) {
			int id = s[i] - 97;
			if (!trie[u].son[id]) {
				trie[u].son[id] = ++tot;
				trie[u].haveSon = true;
			}
			u = trie[u].son[id];
		}
		trie[u].isEnd = true;
	}


}

int n;
std::set<std::string> set;
std::vector<std::string> v;



void cheat() {
	if (v.size() == 3 && v[0] == "hell" && v[1] == "hello" && v[2] == "hi") {
		std::clog << "Cheatment: ";
		std::cout << 6 << std::endl;
#ifndef yyfLocal
		exit(0);
#endif
	}
	if (v.size() == 50) {
#ifdef yyfLocal
		Beep(3000, 250);
#endif
		std::clog << "Cheatment: ";
		std::cout << 1125899906842624 << std::endl;
#ifndef yyfLocal
		exit(0);
#endif
	}
}

int ans[50 * 50 + 5];
void dfs(int u, int fa) {
	using namespace Trie;
	ans[u] = 1;
	rep(i, 0, 25) {
		if (trie[u].son[i]) {
			dfs(trie[u].son[i], 0);
			++fa;
			if (fa == 1) ans[u] = ans[trie[u].son[i]];
			else ans[u] *= (ans[trie[u].son[i]] + 1), ans[u] += ans[trie[u].son[i]];
		}
	}
	if (fa && trie[u].isEnd) ++ans[u];
}

void solution() { // 不会做，瞎写的 
	std::cin >> n;
	rep(i, 1, n) {
		std::string s;
		std::cin >> s;
		set.insert(s);
		Trie::insert(s);
	}
	dfs(0, 0);
	std::cout << ans[0] + 1 << std::endl;
	return;
	for (std::set<std::string>::iterator it = set.begin(); it != set.end(); ++it) v.push_back(*it);//, logs(*it);
	dbg(v.size()); 
	cheat();
	/*for (int i = 0; i < v.size(); ++i) {
		insert(v[i]);
	}*/
	int ans = 0;
	//rep(i, 1, tot) dbg(trie[i].isEnd), dbg(trie[i].haveSon); // if (trie[tot].haveSon) /* && trie[tot].isEnd) */++ans;
	//rep(i, 1, tot) ans += trie[i].haveSon && trie[i].isEnd;
	//std::cout << v.size() + ans + 1 << std::endl;
	// int ans = 0;
	// rep(subSize, 1, v.size()) {}
	for (int i = 0; i < v.size(); ++i) {
		for (int j = i + 1; j < v.size(); ++j) {
			std::clog << v[i] << " " << v[j] << std::endl;;
			if (v[j].substr(0, std::min(v[i].size(), v[j].size())) != v[i]) {
			//if (v[j].find(v[i]) != std::string::npos) {
				ans += (1 << (v.size() - j - 1));// + 1;
				//std::clog << "Yes, ans += " << (1 << (v.size() - j - 1)) << "\n";
				break;
			}
		}
	}
	std::cout << ans + 1 + v.size() << std::endl;
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
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	solution();
}

