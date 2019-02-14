#include <iostream>
#include <algorithm>

int fa[300005];

int find(int x)
{
	if (x == fa[x])
		return x;
	return fa[x] = find(fa[x]);
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	fa[b] = a;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, k, ans = 0;
	std::cin >> n >> k;
	for (int i = 1; i <= 3 * n; ++i)
		fa[i] = i;
	while (k--)
	{
		int command, x, y;
		std::cin >> command >> x >> y;
		if (x > n || y > n)
			++ans;
		else if (command == 1) // 同类 
			if (find(x + n) == find(y) || find(x) == find(y + n)) // 同类不可能有吃与被吃的关系
				++ans;
			else
			{
				// 合并，表示友好关系 
				merge(x, y);
				merge(x + n, y + n);
				merge(x + n * 2, y + n * 2);
			}
		else if (command == 2) // 吃 
		{
			if (find(x) == find(y) || find(x) == find(y + n)) // 怎么可能是同类 / 被吃？ 
				++ans;
			else
			{
				// 合并 
				merge(x + n, y);
				merge(x + n * 2, y + n);
				merge(x, y + n * 2);
			}
		}
	}
	std::cout << ans << std::endl;
}