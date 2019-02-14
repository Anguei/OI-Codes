//【P1816】忠诚 - 洛谷 - 0 
#include <iostream>
#include <algorithm> 

const int kMaxM = 100000; 

int a[kMaxM + 5];

class SegTree
{
public:
	void build(int root, int l, int r)
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
	
	int query(int root, int l, int r, int ql, int qr)
	{
		if (ql > r || qr < l)
		{
			return 0x7fffffff;
		}
		else if (ql <= l && qr >= r)
		{
			return tree[root];
		}
		else
		{
			int mid = (l + r) >> 1;
			return std::min(query(lson(root), l, mid, ql, qr), query(rson(root), mid + 1, r, ql, qr));
		}
	}
	
private:
	int tree[kMaxM << 2];
	
	int lson(int root)
	{
		return root << 1;
	}
	
	int rson(int root)
	{
		return root << 1 | 1;
	}
	
	void pushup(int root)
	{
		tree[root] = std::min(tree[lson(root)], tree[rson(root)]);
	}
} segTree;

int main()
{
	int m, n;
	std::cin >> m >> n;
	for (int i = 1; i <= m; ++i)
		std::cin >> a[i];
		
	segTree.build(1, 1, m);
	
	for (int i = 1; i <= n; ++i)
	{
		int l, r;
		std::cin >> l >> r;
		std::cout << segTree.query(1, 1, m, l, r) << " ";
	}
	std::cout << std::endl;
	
	return 0;
}
