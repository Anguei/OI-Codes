// luogu-judger-enable-o2
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	unsigned T;
	std::cin >> T;
	while (T--)
	{
		unsigned n;
		std::cin >> n;
		using puu = std::pair<unsigned, unsigned>;
		std::vector<puu> v;
		for (unsigned i = 0; i < n; ++i)
		{
			int tmp;
			std::cin >> tmp;
			v.emplace_back(std::make_pair(tmp, i));
		}
		std::sort(v.begin(), v.end());
		unsigned cnt = std::unique(v.begin(), v.end(), [](const puu &p1, const puu &p2)
		{
			return p1.first == p2.first;
		}) - v.begin();
		std::sort(v.begin(), v.begin() + cnt, [](const puu &p1, const puu &p2)
		{
			return p1.second < p2.second;
		});
		for (unsigned i = 0; i < cnt; ++i)
			std::cout << v[i].first << " ";
		std::cout << std::endl;
	}
}