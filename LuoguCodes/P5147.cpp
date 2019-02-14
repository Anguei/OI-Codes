// luogu-judger-enable-o2
// luogu-judger-enable-o2
#ifndef ONLINE_JUDGE
#define yyfLocal
#endif
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
#define pc(x) putchar(x)
#define endln putchar(';\n';)
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

double fed[10000000 + 5];
double f(int n) {
	if (n == 1) return 0;
	if (fed[n]) return fed[n];
	double tot = 0;
	rep(i, 1, n - 1) tot += f(i);
	return fed[n] = (n + tot) / (n - 1);
}

void solution() {
	int n; std::cin >> n; if (n <= 1000000) {
	double tmp = 0, sum = 0;
	rep(i, 2, n) {
		tmp = (i + sum) / (i - 1);
		sum += tmp;
	}
	std::cout << std::fixed << std::setprecision(5) << tmp << std::endl; return; }
    std::cout << std::fixed << std::setprecision(5) << log(n + 1) + 1 + 0.5772156649 << std::endl;
}

signed main() {
#ifdef yyfLocal
	fileIn;
	// fileOut;
#else  
#ifndef ONLINE_JUDGE   
	// freopen(fn".in", "r", stdin);
	// freopen(fn".out", "w", stdout);
#endif
#endif
	logs("main.exe");
	solution();
}