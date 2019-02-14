//【UVA11729】Commando War - 洛谷 - Ac 
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

int main()
{
	int n, Case = 0;
	while (std::cin >> n && n)
	{
		struct Node
		{
			int b, j;
		};
		std::vector<Node> node(n);
		for (int i = 0; i < n; ++i)
			std::cin >> node[i].b >> node[i].j;
		std::sort(node.begin(), node.end(), [](const Node &n1, const Node &n2)
		{
			return n1.j > n2.j;
		});
		int now = 0, ans = 0;
		for (int i = 0; i < n; ++i)
		{
			now += node[i].b;
			ans = std::max(ans, now + node[i].j);
		}
		std::cout << "Case " << ++Case << ": " << ans << std::endl;
	}
}