//【P2089】烤鸡 - 洛谷 - 0 
#include <array>
#include <string>
#include <vector> 
#include <iostream> 
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;
	int cnt = 0;
	//std::vector<std::string> ans;
	std::vector<std::array<int, 10>> ans;
	for (int a = 1; a <= 3; ++a)
		for (int b = 1; b <= 3; ++b)
			for (int c = 1; c <= 3; ++c)
				for (int d = 1; d <= 3; ++d)
					for (int e = 1; e <= 3; ++e)
						for (int f = 1; f <= 3; ++f)
							for (int g = 1; g <= 3; ++g)
								for (int h = 1; h <= 3; ++h)
									for (int i = 1; i <= 3; ++i)
										for (int j = 1; j <= 3; ++j)
											if (a + b + c + d + e + f + g + h + i + j == n)
												ans.push_back({a, b, c, d, e, f, g, h, i, j});
												//ans.push_back(std::string(1, char(a - 48)) + " " + std::string(1, char(b - 48)) + std::string(1, char(c - 48)) + std::string(1, char(d - 48)) + std::string(1, char(e - 48)) + std::string(1, char(f - 48)) + std::string(1, char(g - 48)) + std::string(1, char(h - 48)) + std::string(1, char(i - 48)) + std::string(1, char(j - 48)));
												
	//std::cout << cnt << std::endl;
	//if (!cnt)
	//	return 0;
	//for (int a = 1; a <= 3; ++a)
	//	for (int b = 1; b <= 3; ++b)
	//		for (int c = 1; c <= 3; ++c)
	//			for (int d = 1; d <= 3; ++d)
	//				for (int e = 1; e <= 3; ++e)
	//					for (int f = 1; f <= 3; ++f)
	//						for (int g = 1; g <= 3; ++g)
	//							for (int h = 1; h <= 3; ++h)
	//								for (int i = 1; i <= 3; ++i)
	//									for (int j = 1; j <= 3; ++j)
	//										if (a + b + c + d + e + f + g + h + i + j == n)
	//											std::cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << " " << g << " " << h << " " << i << " " << j << std::endl;
	//std::cout << ans.size() << std::endl;
	//std::sort(ans.begin(), ans.end());
	//if (ans.size())
	//	for (auto i : ans) {
	//		for (auto j : i)
	//			std::cout << j << " ";
	//		std::cout << std::endl;
	//	}
	//std::cout << ans.size() << std::endl;
	//for (auto i : ans)
	//	std::cout << i << std::endl;
	//for (auto i : ans)
	//	std::sort(i.begin(), i.end());
	std::cout << ans.size() << std::endl;
	std::sort(ans.begin(), ans.end());
	for (auto i : ans) {
		for (auto j : i)
			std::cout << j << " ";
		std::cout << std::endl;
	}
}