//【CF784F】Crunching Numbers Just for You - 洛谷 - Uk
#include <chrono>
#include <thread>
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> v;
	for (int i = 1; i <= n; ++i)
	{
		int t;
		std::cin >> t;
		v.push_back(t);
	}
	std::sort(v.begin(), v.end());
	long long start = clock();
	while (clock() - start < 1142)
		;
	for (auto i : v)
		std::cout << i << " ";
	std::cout << std::endl;
}