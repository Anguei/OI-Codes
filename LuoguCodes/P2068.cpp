//【P2068】统计和 - 洛谷 - 0 
#include <iostream>

int n, w;
const int kMaxN = 100000;
int a[kMaxN + 5];

struct SegTree {
	int tree[kMaxN << 2 + 5];
	int lazyTag[kMaxN << 2 + 5];
	constexpr int lson(int x) { return x << 1; }
	constexpr int rson(int x) { return x << 1 | 1; }
	
	inline void pushup(int p) {
		tree[p] = tree[lson(p)] + tree[rson(p)];
	}
	
	inline void pushdown(int p, int l, int r) {
		if (lazyTag[p]) {
			lazyTag[lson(p)] += lazyTag[p];
			lazyTag[rson(p)] += lazyTag[p];
			int mid = (l + r) >> 1;
			tree[lson(p)] += lazyTag[p] * (mid - l + 1);
			tree[rson(p)] += lazyTag[p] * (r - mid); 
			lazyTag[p] = 0;
		}
	}
	
	inline void build(int p, int l, int r) {
		if (l == r) {
			tree[p] += a[l];
		} else {
			int mid = (l + r) >> 1;
			build(lson(p), l, mid);
			build(rson(p), mid + 1, r);
		}
	}
	
	inline void update(int p, int l, int r, int ul, int ur, int val) {
		if (ul > r || ur < l) {
			;
		} else if (ul <= l && ur >= r) {
			lazyTag[p] += val;
			tree[p] = val * (r - l + 1);
		} else {
			pushdown(1, l, r);
			int mid = (l + r) >> 1;
			update(p, l, mid, ul, ur, val);
			update(p, mid + 1, r, ul, ur, val);
			pushup(p);
		}
	}
	
	inline int query(int p, int l, int r, int ql, int qr) {
		if (ql > r || qr < l) {
			;
		} else if (ql <= l && qr >= r) {
			return tree[p];
		} else {
			pushdown(p, l, r);
			int mid = (l + r) >> 1;
			return query(lson(p), l, mid, ql, qr) + query(rson(p), mid + 1, r, ql, qr);
		}
	}
} segTree;

struct BinaryIndexTree {
	int c[kMaxN + 5];
	constexpr int lowbit(int x) { return x & -x; }
	
	inline void update(int i, int val) {
		while (i <= n) {
			c[i] += val;
			i += lowbit(i);
		}
	}
	
	inline int sum(int i) {
		int res = 0;
		while (i > 0) {
			res += c[i];
			i -= lowbit(i);
		}
		return res;
	}
} bit;

int main() {
	std::cin >> n >> w;
	//segTree.build(1, 1, n);
	while (w--) {
		char command;
		std::cin >> command;
		if (command == ';x';) {
			int a, b;
			std::cin >> a >> b;
			bit.update(a, b);
			//segTree.update(1, 1, n, a, a, b);
		} else if (command == ';y';) {
			int a, b;
			std::cin >> a >> b;
			std::cout << bit.sum(b) - bit.sum(a - 1) << std::endl;
			//std::cout << segTree.query(1, 1, n, a, b) << std::endl;
		}
	}
}