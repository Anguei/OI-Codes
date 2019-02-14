//【P1104】生日 - 洛谷 - 0 
/**/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

inline bool cmp(const std::pair<std::string, std::pair<std::pair<int, std::pair<int, int>>, int>> &a, const std::pair<std::string, std::pair<std::pair<int, std::pair<int, int>>, int>> &b) {
	std::string as = a.first, bs = b.first;
	int ay = a.second.first.first, by = b.second.first.first;
	int am = a.second.first.second.first, bm = b.second.first.second.first;
	int ad = a.second.first.second.second, bd = b.second.first.second.second;
	int ai = a.second.second, bi = b.second.second;
	if (a.second.first.first != b.second.first.first)
		return a.second.first.first < b.second.first.first;
	else if (a.second.first.second.first != b.second.first.second.first)
		return a.second.first.second.first < b.second.first.second.first;
	else if (a.second.first.second.second != b.second.first.second.second)
		return a.second.first.second.second < b.second.first.second.second;
	else
		return a.second.second > b.second.second;
}

inline std::pair<std::string, std::pair<std::pair<int, std::pair<int, int>>, int>> pair(std::string s, int y, int m, int d, int i) {
	return std::make_pair(s, std::make_pair(std::make_pair(y, std::make_pair(m, d)), i));
}

int main() {
	register int n;
	std::cin >> n;
	typedef std::pair<std::string, std::pair<std::pair<int, std::pair<int, int>>, int>> psiiii;
	std::vector<std::pair<std::string, std::pair<std::pair<int, std::pair<int, int>>, int>>> v;
	for (register int i = 0; i < n; ++i) {
	 	std::string s;
	 	std::cin >> s;
	 	int y, m, d;
	 	std::cin >> y >> m >> d;
	 	v.push_back(pair(s, y, m, d, i + 1));
	 }
	 std::sort(std::begin(v), std::end(v), cmp);
	 for (std::vector<std::pair<std::string, std::pair<std::pair<int, std::pair<int, int>>, int>>>::iterator it = std::begin(v); it != std::end(v); ++it) {
	 	std::cout << (*it).first << std::endl;
	 }
	return 0;
}
