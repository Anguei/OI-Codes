//【P3373】【模板】线段树 2 - 洛谷 - 100 
// 借巨量代码线段树，来改善一下自己的码风！

#include <iostream>
#include <algorithm>

namespace SegTree1
{
	// 时隔一个星期，回来复习线段树的板子。
	// update 的时候忘记了更新 lazyTag。
	// 依然不是很懂什么时候需要 pushdown。
	// 或许需要自己画点图出来。

	using ll = long long;

	constexpr int kMaxN = 100000;

	int a[kMaxN + 5];

	class SegTree
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
	} segTree;

	int main()
	{
		int n, m;
		std::cin >> n >> m;
		for (int i = 1; i <= n; ++i)
		{
			std::cin >> a[i];
		}

		segTree.build(1, 1, n);

		for (int i = 1; i <= m; ++i)
		{
			int command;
			std::cin >> command;
			if (command == 1)
			{
				int l, r, val;
				std::cin >> l >> r >> val;
				segTree.update(1, 1, n, l, r, val);
			}
			else if (command == 2)
			{
				int l, r;
				std::cin >> l >> r;
				std::cout << segTree.query(1, 1, n, l, r) << std::endl;
			}
		}

		return 0;
	}
}


namespace SegTree2
{
	// AC 过线段树模板一之后，手打了几遍模板，虐了几次 P1001.
	// 基本的写法已经掌握的差不多了，但还不能算十深入理解。
	// 打一个线段树二的模板。需要注意的细节挺多的。参照了题解。
	// 题解的码风可真是不好。

	using ll = long long;

	constexpr int kMaxN = 100000;

	int P;
	int a[kMaxN + 5];

	class SegTree
	{
	public:
		inline void build(int root, int l, int r)
		{
			addLazyTag[root] = 0;
			mulLazyTag[root] = 1;
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

		inline void mulUpdate(int root, int l, int r, int ul, int ur, int val)
		{
			if (ul > r || ur < l)
			{
				return;
			}
			else if (ul <= l && ur >= r)
			{
				tree[root] = (tree[root] * val) % P;
				mulLazyTag[root] = (mulLazyTag[root] * val) % P;
				addLazyTag[root] = (addLazyTag[root] * val) % P;
			}
			else
			{
				pushdown(root, l, r);
				int mid = (l + r) >> 1;
				mulUpdate(lson(root), l, mid, ul, ur, val);
				mulUpdate(rson(root), mid + 1, r, ul, ur, val);
				pushup(root);
			}
		}

		inline void addUpdate(int root, int l, int r, int ul, int ur, int val)
		{
			if (ul > r || ur < l)
			{
				return;
			}
			else if (ul <= l && ur >= r)
			{
				addLazyTag[root] = (addLazyTag[root] + val) % P;
				tree[root] = (tree[root] + val * (r - l + 1)) % P;
			}
			else
			{
				pushdown(root, l, r);
				int mid = (l + r) >> 1;
				addUpdate(lson(root), l, mid, ul, ur, val);
				addUpdate(rson(root), mid + 1, r, ul, ur, val);
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
				return (query(lson(root), l, mid, ql, qr) + query(rson(root), mid + 1, r, ql, qr)) % P;
			}
		}

	private:
		ll tree[kMaxN << 2];
		ll addLazyTag[kMaxN << 2];
		ll mulLazyTag[kMaxN << 2];

		constexpr int lson(int x)
		{
			return x << 1;
		}

		constexpr int rson(int x)
		{
			return x << 1 | 1;
		}

		inline void pushup(int root)
		{
			tree[root] = (tree[lson(root)] + tree[rson(root)]) % P;
		}

		inline void pushdown(int root, int l, int r)
		{
			mulLazyTag[lson(root)] = (mulLazyTag[lson(root)] * mulLazyTag[root]) % P;
			mulLazyTag[rson(root)] = (mulLazyTag[rson(root)] * mulLazyTag[root]) % P;
			addLazyTag[lson(root)] = (addLazyTag[lson(root)] * mulLazyTag[root] + addLazyTag[root]) % P;
			addLazyTag[rson(root)] = (addLazyTag[rson(root)] * mulLazyTag[root] + addLazyTag[root]) % P;
			int mid = (l + r) >> 1;
			tree[lson(root)] = (tree[lson(root)] * mulLazyTag[root] + addLazyTag[root] * (mid - l + 1)) % P;
			tree[rson(root)] = (tree[rson(root)] * mulLazyTag[root] + addLazyTag[root] * (r - mid)) % P;
			mulLazyTag[root] = 1;
			addLazyTag[root] = 0;
		}
	} segTree;

	int main()
	{
		int n, m;
		std::cin >> n >> m >> P;
		for (int i = 1; i <= n; ++i)
			std::cin >> a[i];
		segTree.build(1, 1, n);
		for (int i = 1; i <= m; ++i)
		{
			int command;
			std::cin >> command;
			if (command == 1)
			{
				int l, r, val;
				std::cin >> l >> r >> val;
				segTree.mulUpdate(1, 1, n, l, r, val);
			}
			else if (command == 2)
			{
				int l, r, val;
				std::cin >> l >> r >> val;
				segTree.addUpdate(1, 1, n, l, r, val);
			}
			else if (command == 3)
			{
				int l, r;
				std::cin >> l >> r;
				std::cout << segTree.query(1, 1, n, l, r) << std::endl;
			}
		}

		return 0;
	}
}

int main()
{
	//SegTree1::main();
	SegTree2::main();

	return 0;
}