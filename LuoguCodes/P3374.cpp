#include <iostream>
#include <algorithm>

/*----------------------------------------
* 3.18 星期日 晚上
* 敲三个线段树的板子来巩固知识
* 分别是模板 1、模板 2、[JSOI2008] 最大数
* 对线段树不太懂的地方依然用注释标出来
* 什么时候才能不忘记 build 啊
* 再敲两个树状数组的板子
* 分别是模板 1、模板 2
---------------------------------------*/

// P3372
namespace SegTreeTemplate1
{
	using ll = long long;

	constexpr int kMaxN = 100000;

	int a[kMaxN + 5];

	class SegTreeTemplate1
	{
	public:
		inline void build(int root, int l, int r)
		{
			if (l == r)
			{
				tree[root] = a[l];
			}
			else
			{
				int mid = (l + r) >> 1;
				build(lson(root), l, mid);
				build(rson(root), mid + 1, r);
				pushup(root);
			}
		}

		inline void update(int root, int l, int r, int ul, int ur, int val)
		{
			if (ul > r || ur < l)
			{
				return;
			}
			else if (ul <= l && ur >= r)
			{
				lazyTag[root] += val;
				tree[root] += val * (r - l + 1);
			}
			else
			{
				pushdown(root, l, r);
				int mid = (l + r) >> 1;
				update(lson(root), l, mid, ul, ur, val);
				update(rson(root), mid + 1, r, ul, ur, val);
				pushup(root);
			}
		}

		inline ll query(int root, int l, int r, int ql, int qr)
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
				pushdown(root, l, r);
				int mid = (l + r) >> 1;
				return query(lson(root), l, mid, ql, qr) + query(rson(root), mid + 1, r, ql, qr);
			}
		}

	private:
		ll tree[kMaxN << 2];
		ll lazyTag[kMaxN << 2];

		constexpr int lson(int root)
		{
			return root << 1;
		}

		constexpr int rson(int root)
		{
			return root << 1 | 1;
		}

		inline void pushup(int root)
		{
			tree[root] = tree[lson(root)] + tree[rson(root)];
		}

		inline void pushdown(int root, int l, int r)
		{
			if (lazyTag[root])
			{
				lazyTag[lson(root)] += lazyTag[root];
				lazyTag[rson(root)] += lazyTag[root];
				int mid = (l + r) >> 1;
				tree[lson(root)] += lazyTag[root] * (mid - l + 1);
				tree[rson(root)] += lazyTag[root] * (r - mid);
				lazyTag[root] = 0;
			}
		}
	} segTreeTemplate1;

	int main()
	{
		std::ios::sync_with_stdio(false);
		int n, m;
		std::cin >> n >> m;
		for (int i = 1; i <= n; ++i)
			std::cin >> a[i];

		segTreeTemplate1.build(1, 1, n);

		for (int i = 1; i <= m; ++i)
		{
			int command;
			std::cin >> command;
			if (command == 1)
			{
				int l, r, val;
				std::cin >> l >> r >> val;
				segTreeTemplate1.update(1, 1, n, l, r, val);
			}
			else if (command == 2)
			{
				int l, r;
				std::cin >> l >> r;
				std::cout << segTreeTemplate1.query(1, 1, n, l, r) << std::endl;
			}
		}

		return 0;
	}
}

// P3373
namespace SegTreeTemplate2
{
	using ll = long long;

	const int kMaxN = 100000;

	int a[kMaxN + 5];

	class SegTreeTemplate2
	{
	public:
		inline void build(int root, int l, int r, int mod)
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

		inline void updateMul(int root, int l, int r, int ul, int ur, int val, int mod)
		{
			if (ul > r || ur < l)
			{
				return;
			}
			else if (ul <= l && ur >= r)
			{
				lazyTagMul[root] = (lazyTagMul[root] * val) % mod;
				lazyTagAdd[root] = (lazyTagAdd[root] * val) % mod;
				tree[root] = (tree[root] * val) % mod; // 为什么这里不再乘上 (r - l + 1) ？
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

		inline void updateAdd(int root, int l, int r, int ul, int ur, int val, int mod)
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

		inline ll query(int root, int l, int r, int ql, int qr, int mod)
		{
			if (ql > r || qr < l)
			{
				return 0;
			}
			else if (ql <= l && qr >= r)
			{
				return tree[root] % mod;
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
		ll lazyTagAdd[kMaxN << 2];
		ll lazyTagMul[kMaxN << 2];

		constexpr int lson(int root)
		{
			return root << 1;
		}

		constexpr int rson(int root)
		{
			return root << 1 | 1;
		}

		inline void pushup(int root, int mod)
		{
			tree[root] = (tree[lson(root)] + tree[rson(root)]) % mod;
		}

		inline void pushdown(int root, int l, int r, int mod)
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
	} segTreeTemplate2;

	int main()
	{
		std::ios::sync_with_stdio(false);
		int n, m, mod;
		std::cin >> n >> m >> mod;
		for (int i = 1; i <= n; ++i)
			std::cin >> a[i];

		segTreeTemplate2.build(1, 1, n, mod); // 忘记 build 线段树太珂怕了！

		for (int i = 1; i <= m; ++i)
		{
			int command;
			std::cin >> command;
			if (command == 1)
			{
				int l, r, val;
				std::cin >> l >> r >> val;
				segTreeTemplate2.updateMul(1, 1, n, l, r, val, mod);
			}
			else if (command == 2)
			{
				int l, r, val;
				std::cin >> l >> r >> val;
				segTreeTemplate2.updateAdd(1, 1, n, l, r, val, mod);
			}
			else if (command == 3)
			{
				int l, r;
				std::cin >> l >> r;
				std::cout << segTreeTemplate2.query(1, 1, n, l, r, mod) << std::endl;
			}
		}

		return 0;
	}
}

// P1198
namespace SegTreeJsoi2008
{
	using ll = long long;

	const int kMaxM = 200000;

	class SegTreeJsoi2008
	{
	public:
		inline void sinUpdate(int root, int l, int r, int pos, int val)
		{
			if (l == r)
			{
				tree[root] = val;
			}
			else
			{
				int mid = (l + r) >> 1;
				if (pos <= mid)
				{
					sinUpdate(lson(root), l, mid, pos, val);
				}
				else if (pos > mid)
				{
					sinUpdate(rson(root), mid + 1, r, pos, val);
				}
				pushup(root);
			}
		}

		inline int query(int root, int l, int r, int ql, int qr)
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
				int mid = (l + r) >> 1;
				return std::max(query(lson(root), l, mid, ql, qr), query(rson(root), mid + 1, r, ql, qr));
			}
		}

	private:
		int tree[kMaxM << 2];

		constexpr int lson(int root)
		{
			return root << 1;
		}

		constexpr int rson(int root)
		{
			return root << 1 | 1;
		}

		inline void pushup(int root)
		{
			tree[root] = std::max(tree[lson(root)], tree[rson(root)]);
		}
	} segTreeJsoi2008;

	int main()
	{
		std::ios::sync_with_stdio(false);
		int size = 0;
		int t = 0;
		int m, mod;
		std::cin >> m >> mod;
		for (int i = 1; i <= m; ++i)
		{
			char command;
			std::cin >> command;
			if (command == ';Q';)
			{
				int l;
				std::cin >> l;
				std::cout << (t = segTreeJsoi2008.query(1, 1, kMaxM, size - l + 1, size)) << std::endl;
			}
			else if (command == ';A';)
			{
				ll n;
				std::cin >> n;
				++size;
				segTreeJsoi2008.sinUpdate(1, 1, kMaxM, size, (n % mod + t) % mod);
			}
		}

		return 0;
	}
}

// P3374
namespace BitTemplate1
{
	const int kMaxN = 500000;

	class BitTemplate1
	{
	public:
		inline void update(int pos, int val, int n)
		{
			while (pos <= n)
			{
				bit[pos] += val;
				pos += lowbit(pos);
			}
		}

		inline int query(int pos, int n)
		{
			int res = 0;
			while (pos > 0)
			{
				res += bit[pos];
				pos -= lowbit(pos);
			}
			return res;
		}

	private:
		int bit[kMaxN + 5];

		constexpr int lowbit(int x)
		{
			return x & -x;
		}
	} bitTemplate1;

	int main()
	{
		std::ios::sync_with_stdio(false);
		int n, m;
		std::cin >> n >> m;
		for (int i = 1; i <= n; ++i)
		{
			int val;
			std::cin >> val;
			bitTemplate1.update(i, val, n);
		}
		for (int i = 1; i <= m; ++i)
		{
			int command;
			std::cin >> command;
			if (command == 1)
			{
				int pos, val;
				std::cin >> pos >> val;
				bitTemplate1.update(pos, val, n);
			}
			else if (command == 2)
			{
				int l, r;
				std::cin >> l >> r;
				std::cout << bitTemplate1.query(r, n) - bitTemplate1.query(l - 1, n) << std::endl;
			}
		}

		return 0;
	}
}

// P3368
namespace BitTemplate2
{
	const int kMaxN = 500000;

	class BitTemplate2
	{
	public:
		inline void update(int pos, int val, int n)
		{
			while (pos <= n)
			{
				bit[pos] += val;
				pos += lowbit(pos);
			}
		}

		inline int query(int pos, int n)
		{
			int res = 0;
			while (pos > 0)
			{
				res += bit[pos];
				pos -= lowbit(pos);
			}
			return res;
		}

	private:
		int bit[kMaxN + 5];

		constexpr int lowbit(int x)
		{
			return x & -x;
		}
	} bitTemplate2;

	int main()
	{
		std::ios::sync_with_stdio(false);
		int n, m;
		std::cin >> n >> m;
		int last = 0;
		for (int i = 1; i <= n; ++i)
		{
			int val;
			std::cin >> val;
			bitTemplate2.update(i, val - last, n);
			last = val;
		}
		for (int i = 1; i <= m; ++i)
		{
			int command;
			std::cin >> command;
			if (command == 1)
			{
				int l, r, val;
				std::cin >> l >> r >> val;
				bitTemplate2.update(l, val, n);
				bitTemplate2.update(r + 1, -val, n);
			}
			else if (command == 2)
			{
				int pos;
				std::cin >> pos;
				std::cout << bitTemplate2.query(pos, n) << std::endl;
			}
		}

		return 0;
	}
}


int main()
{
	//SegTreeTemplate1::main(); // Wa
	//SegTreeTemplate2::main(); // Ac
	//SegTreeJsoi2008::main(); // Ac
	BitTemplate1::main(); // Ac
	//BitTemplate2::main(); // Ac

	return 0;
}