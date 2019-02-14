//【CF994A】Fingerprints - 洛谷 - Ac 
#include <set>
#include <iostream>

int n, m;
int x[15];//, y[15]
std::set<int> y;

int main()
{
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		int tmp;
		std::cin >> tmp;
		x[i] = tmp;
	}
	for (int i = 1; i <= m; ++i)
	{
		int tmp;
		std::cin >> tmp;
		y.insert(tmp);
	}
	for (int i = 1; i <= n; ++i)
		if (!y.count(x[i]))
			x[i] = -1;
	for (int i = 1; i <= n; ++i)
		if (x[i] != -1)
			std::cout << x[i] << " ";
	std::cout << std::endl;
}