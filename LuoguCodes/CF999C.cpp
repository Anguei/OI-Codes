#include <string>
#include <iostream>
#include <algorithm>

struct Node
{
	char c;
	int id;
} node[400000 + 5];

int main()
{
	int n, k;
	std::cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		std::cin >> node[i].c;
		node[i].id = i;
	}
	std::sort(node + 1, node + n + 1, [](const Node &n1, const Node &n2)
	{
		if (n1.c != n2.c)
			return n1.c < n2.c;
		return n1.id < n2.id;
	});
	for (int i = 1; i <= k; ++i)
		node[i].c = 0;
	std::sort(node + 1, node + n + 1, [](const Node &n1, const Node &n2)
	{
		return n1.id < n2.id;
	});
	for (int i = 1; i <= n; ++i)
		if (node[i].c != 0)
			std::cout << node[i].c;
	std::cout << std::endl;
}