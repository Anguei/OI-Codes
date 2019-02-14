#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define lson (root << 1)
#define rson (root << 1 | 1)
#define mid ((l + r) >> 1)
#define lowbit(x) ((x) & -(x))
#define ll long long
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x" = " << (x) << std::endl
#else
#define dbg(x) ;
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

const int N = 200000 + 5;
int n, m;
int a[N], st[N][20];

void init_st() {
	rep(i, 1, n) st[i][0] = a[i];
	for (int j = 1; (1 << j) <= n; ++j)
		for (int i = 1; i + (1 << j) - 1 <= n; ++i)
			st[i][j] = std::max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

int query_st(int l, int r) {
	int k = log(r - l + 1) / log(2);
	return std::max(st[l][k], st[r - (1 << k) + 1][k]);
}

class SegTree {
public:
	void build(int root, int l, int r) {
		if (l == r) { max[root] = a[l]; return; }
		build(lson, l, mid);
		build(rson, mid + 1, r);
		pushup(root);
	}
	
	void update(int root, int l, int r, int ul, int ur, int val) {
		if (ul > r || ur < l) return;
		if (ul <= l && ur >= r) { max[root] = std::max(max[root], val); return; }
		update(lson, l, mid, ul, ur, val);
		update(rson, mid + 1, r, ul, ur, val);
		pushup(root);
	}
	
	int query(int root, int l, int r, int ql, int qr) {
		if (ql > r || qr < l) return 0;
		if (ql <= l && qr >= r) return max[root];
		return std::max(query(lson, l, mid, ql, qr), query(rson, mid + 1, r, ql, qr));
	}
private:
	int max[N << 2], lazy[N << 2];
	void pushup(int root) { max[root] = std::max(max[lson], max[rson]);	}
} segTree;

signed main() {
#ifdef yyfLocal
	freopen("testdata.in", "r", stdin);
	freopen("testdata.out", "w", stdout);
#endif
	n = read(), m = read();
	rep(i, 1, n) a[i] = read();
	//rep(i, 1, n) print(a[i]), putchar('; ';); puts("");
	//init_st();
	segTree.build(1, 1, n);
	while (m--) {
		char opt; std::cin >> opt; int x = read(), y = read();
		if (opt == ';U';) {
			if (a[x] < y) {
				a[x] = y;
				//rep(i, 1, n) print(a[i]), putchar('; ';); puts("");
				//init_st();
				segTree.update(1, 1, n, x, x, y);
			}
		} else if (opt == ';Q';){
			//printf("[%d, %d]: ", x, y), 
			//print(query_st(x, y)), puts("");
			print(segTree.query(1, 1, n, x, y)), puts("");
		}
	}
}