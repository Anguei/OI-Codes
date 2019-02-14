#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#ifndef ONLINE_JUDGE
#define dbg(x) std::clog << #x" = " << (x) << std::endl
#else
#define dbg(x) x
#endif

int read() {
	int res = 0; char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) res = res * 10 + ch - 48, ch = getchar();
	return res;
}

const int N = 200000 + 5;

struct Q {
	int a, b, c;
	Q(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
	Q() {}
	bool operator < (const Q &rhs) const {
		return c > rhs.c;
	}
} q[N];
int fa[N], tmp[N << 1];

int find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

void merge(int a, int b) {
	a = find(a), b = find(b);
	fa[b] = a;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("testdata.in", "r", stdin);
#endif
	int T = read();
	dbg(T);
	while (T--) {
		int n = read(), tot = 0;
		
		rep(i, 1, n) {
			int a = read(), b = read(), c = read();
			q[i] = Q(a, b, c);
			tmp[++tot] = a; tmp[++tot] = b;
		}
		//dbg(tot);
		
		std::sort(q + 1, q + n + 1);
		std::sort(tmp + 1, tmp + tot + 1);
		tot = std::unique(tmp + 1, tmp + tot + 1) - tmp - 1;
		dbg(tot);
		rep(i, 1, tot) fa[i] = i;
		
		bool flag = true;
		rep(i, 1, n) {
			q[i].a = std::lower_bound(tmp + 1, tmp + tot + 1, q[i].a) - tmp;
			q[i].b = std::lower_bound(tmp + 1, tmp + tot + 1, q[i].b) - tmp;
			if (q[i].c) merge(q[i].a, q[i].b);
			else if (find(q[i].a) == find(q[i].b)) {
				//dbg(i);
				flag = false;
				break;
			}
		}
		
		puts(flag ? "YES" : "NO");
	}
}
