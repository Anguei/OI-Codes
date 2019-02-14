#include <vector>
#include <iostream>
#include <algorithm>

const int kMaxN = 200000;

struct Node
{
	int a, b;
} node[kMaxN + 5];

bool cmp(const Node &n1, const Node &n2)
{
	return n1.a < n2.a;
}

int main()
{
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> node[i].a >> node[i].b;
	std::sort(node, node + n, cmp);
	std::vector<int> dp(n);
	std::fill(dp.begin(), dp.end(), 0x3f3f3f3f);
	for (int i = 0; i < n; ++i)
		*std::lower_bound(dp.begin(), dp.end(), node[i].b) = node[i].b;
	std::cout << std::lower_bound(dp.begin(), dp.end(), 0x3f3f3f3f) - dp.begin() << std::endl;
}