//【P1198】[JSOI2008] 最大数 - 洛谷 - 0 
#include <iostream>
#include <algorithm>

const int kMaxM = 200000;

int m, MOD, t = 0, size = 0;

class SegTreeMax
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
				sinUpdate(lson(root), l, mid, pos, val);
			else if (pos > mid)
				sinUpdate(rson(root), mid + 1, r, pos, val);
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
    static const int kMaxM = 200000;
    
    int tree[kMaxM << 2];
    
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
        tree[root] = std::max(tree[lson(root)], tree[rson(root)]);
    }	
    
} segTreeMax;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> m >> MOD;
    
    //segTreeMax.build(1, 1, 200000 + 5);
    
    for (int i = 1; i <= m; ++i)
    {
        char command;
        std::cin >> command;
        if (command == ';Q';)
        {
            int l;
            std::cin >> l;
            //if (l == 0)
            //	std::cout << (t = 0) << std::endl;
            //else
            	std::cout << (t = segTreeMax.query(1, 1, kMaxM + 5, size - l + 1, size)) << std::endl;
        }
        else if (command == ';A';)
        {
            ++size;
            int n;
            std::cin >> n;
            //segTreeMax.update(1, 1, size, size, size, (n % MOD + t) % MOD);
            segTreeMax.sinUpdate(1, 1, kMaxM + 5, size, (n % MOD + t) % MOD);
        }
    }
    
    return 0;
}