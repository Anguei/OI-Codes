#pragma GCC optimize(3)
#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
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
	if (x < 0) x = -x, putchar(';-';);
	if (x > 9) print(x / 10);
	putchar(x % 10 + 48);
}

const int N = 100000;
int fa[N], enemy[N];

int find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	fa[b] = a;
}

int main() {
	//freopen("easy.in", "r", stdin);
	//freopen("easy.out", "w", stdout);
	int n = read(), m = read();
	rep(i, 1, n) fa[i] = i;
	rep(i, 1, m) {
		char ch; int a, b;
		std::cin >> ch; a = read(); b = read();
		if (ch == ';F';) merge(a, b);
		else {
			if (!enemy[a]) enemy[a] = b;
			else merge(enemy[a], b);
			if (!enemy[b]) enemy[b] = a;
			else merge(enemy[b], a);
		}
	}
	int ans = 0;
	rep(i, 1, n) if (fa[i] == i) ++ans;
	print(ans), puts("");
}
