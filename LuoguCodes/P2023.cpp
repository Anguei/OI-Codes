// 微机课撸线段树真爽！
// 或许有助于回复心情。 
// 竟然有错误没调出来！ 
// 原来是 updateAdd 的时候把 + 写成了 * 

#include <iostream>

const int kMaxN = 100000;

using ll = long long;

ll a[kMaxN + 5];

class SegTree
{
public:
	void build(int root, int l, int r, int mod)
	{
		lazyTagMul[root] = 1;
		lazyTagAdd[root] = 0;
		if (l == r)
		{
			tree[root] = a[l];
		}
		else
		{
			int mid = (l + r) >> 1;
			build(lson(root), l, mid, mod);
			build(rson(root), mid + 1, r, mod);
			pushup(root, mod);
		}
	}
	
	void updateMul(int root, int l, int r, int ul, int ur, int val, int mod)
	{
		if (ul > r || ur < l)
		{
			return;
		}
		else if (ul <= l && ur >= r)
		{	
			lazyTagMul[root] = (lazyTagMul[root] * val) % mod;
			lazyTagAdd[root] = (lazyTagAdd[root] * val) % mod;
			tree[root] = (tree[root] * val) % mod;
		}
		else
		{
			pushdown(root, l, r, mod);
			int mid = (l + r) >> 1;
			updateMul(lson(root), l, mid, ul, ur, val, mod);
			updateMul(rson(root), mid + 1, r, ul, ur, val, mod);
			pushup(root, mod);
		}
	}
	
	void updateAdd(int root, int l, int r, int ul, int ur, int val, int mod)
	{
		if (ul > r || ur < l)
		{
			return;
		}
		else if (ul <= l && ur >= r)
		{
			lazyTagAdd[root] = (lazyTagAdd[root] + val) % mod;
			tree[root] = (tree[root] + val * (r - l + 1)) % mod;
		}
		else
		{
			pushdown(root, l, r, mod);	
			int mid = (l + r) >> 1;
			updateAdd(lson(root), l, mid, ul, ur, val, mod);
			updateAdd(rson(root), mid + 1, r, ul, ur, val, mod);
			pushup(root, mod);
		}
	}
	
	ll query(int root, int l, int r, int ql, int qr, int mod)
	{
		if (ql > r || qr < l)
		{
			return 0;
		}
		else if (ql <= l && qr >= r)
		{
			return tree[root];
		}
		else
		{
			pushdown(root, l, r, mod);
			int mid = (l + r) >> 1;
			return (query(lson(root), l, mid, ql, qr, mod) + query(rson(root), mid + 1, r, ql, qr, mod)) % mod;
		}
	}

private:
	ll tree[kMaxN << 2];
	ll lazyTagMul[kMaxN << 2];
	ll lazyTagAdd[kMaxN << 2];
	
	constexpr int lson(int root)
	{
		return root << 1;
	}
	
	constexpr int rson(int root)
	{
		return root << 1 | 1;
	}
	
	void pushup(int root, int mod)
	{
		tree[root] = (tree[lson(root)] + tree[rson(root)]) % mod;
	}
	
	void pushdown(int root, int l, int r, int mod)
	{
		lazyTagMul[lson(root)] = (lazyTagMul[lson(root)] * lazyTagMul[root]) % mod;
		lazyTagMul[rson(root)] = (lazyTagMul[rson(root)] * lazyTagMul[root]) % mod;
		lazyTagAdd[lson(root)] = (lazyTagAdd[lson(root)] * lazyTagMul[root] + lazyTagAdd[root]) % mod;
		lazyTagAdd[rson(root)] = (lazyTagAdd[rson(root)] * lazyTagMul[root] + lazyTagAdd[root]) % mod;
		int mid = (l + r) >> 1;
		tree[lson(root)] = (tree[lson(root)] * lazyTagMul[root] + lazyTagAdd[root] * (mid - l + 1)) % mod;
		tree[rson(root)] = (tree[rson(root)] * lazyTagMul[root] + lazyTagAdd[root] * (r - mid)) % mod;
		lazyTagMul[root] = 1;
		lazyTagAdd[root] = 0;
	}
} segTree;

int main()
{
	std::ios::sync_with_stdio(false);
	int n, mod;
	std::cin >> n >> mod;
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i];
	segTree.build(1, 1, n, mod);
	int m;
	std::cin >> m;
	for (int i = 1; i <= m; ++i)
	{
		int command;
		std::cin >> command;
		if (command == 1)
		{
			int l, r, val;
			std::cin >> l >> r >> val;
			segTree.updateMul(1, 1, n, l, r, val, mod);
		}
		else if (command == 2)
		{
			int l, r, val;
			std::cin >> l >> r >> val;
			segTree.updateAdd(1, 1, n, l, r, val, mod);
		}
		else if (command == 3)
		{
			int l, r;
			std::cin >> l >> r;
			std::cout << segTree.query(1, 1, n, l, r, mod) << std::endl;
		}
	}
	
	return 0;
}