//【CF1006B】Polycarps Practice - 洛谷 - Ac
#include <numeric>
#include <iostream>
#include <algorithm>
#include <functional>

struct Node
{
	int id, val;
};

Node a[2005];
//int a[2005];

int main()
{
	int n, k;
	std::cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i].val, a[i].id = i;
	std::sort(a + 1, a + n + 1, [](const Node &n1, const Node &n2)
	{
		return n1.val > n2.val;
	});
	int sum = 0;
	for (int i = 1; i <= k; ++i) 
		sum += a[i].val;
	std::cout << sum << std::endl;
	//a[k].id = n;
	std::sort(a + 1, a + k + 1, [](const Node &n1, const Node &n2)
	{
		return n1.id < n2.id;
	});
	int last = 0;
	a[k].id = n;
	for (int i = 1; i <= k; ++i)	
	{
		std::cout << a[i].id - last << " ";
		last = a[i].id;
	}
	std::cout << std::endl;
}