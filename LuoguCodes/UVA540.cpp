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

const int T = 1000 + 5;
int t;
std::queue<int> q[T];
std::map<int, int> belong;

bool find(int tid) {
	std::queue<int> q2 = q[0];
	while (!q2.empty()) { if (q2.front() == tid) return true; q2.pop(); }
	return false;
}

void solution() {
	belong.clear();
	rep(i, 0, T - 1) while (!q[i].empty()) q[i].pop();
	rep(i, 1, t) {
		int n = read();
		rep(j, 1, n) {
            int num = read();
            belong[num] = i;
        }
	}
	std::string s; while (std::cin >> s && s != "STOP") {
		if (s == "ENQUEUE") {
			int num = read();
			q[belong[num]].push(num);
			if (q[belong[num]].size() == 1) q[0].push(belong[num]);
		} else if (s == "DEQUEUE") {
			int front = q[q[0].front()].front(); q[q[0].front()].pop();
			print(front), puts("");
			if (q[belong[front]].empty()) q[0].pop();
		}
	}
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
	// int kase = 0; while (std::cin >> t && t) if (kase) puts(""), printf("Scenario #%lld\n", ++kase), solution(); else printf("Scenario #%lld\n", ++kase), solution();
    int kase = 0; while (std::cin >> t && t) printf("Scenario #%lld\n", ++kase), solution(), puts("");
}