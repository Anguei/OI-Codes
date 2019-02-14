//¡¾CF3C¡¿Tic-tac-toe - Âå¹È - Ac
#include <bits/stdc++.h>

int main()
{
	std::vector<std::string> l(3), mul;
	std::cin >> l.at(0) >> l.at(1) >> l.at(2);
	int cx = 0, c0 = 0, b;
	for (auto &i : l) for (auto j : i) if (j == ';X';) ++cx; else if (j == ';0';) ++c0;
	for (auto &i : l) mul.emplace_back(i);
	mul.emplace_back(std::string(1, l.at(0).at(0)) + std::string(1, l.at(1).at(1)) + std::string(1, l.at(2).at(2))); mul.emplace_back(std::string(1, l.at(0).at(2)) + std::string(1, l.at(1).at(1)) + std::string(1, l.at(2).at(0)));
	for (int i = 0; i < 3; ++i) { std::string tmp; for (int j = 0; j < 3; ++j) tmp += std::string(1, l.at(j).at(i)); mul.emplace_back(tmp); }
	b = (std::find(mul.begin(), mul.end(), "XXX") != mul.end()) + 2 * (std::find(mul.begin(), mul.end(), "000") != mul.end()) - 1;
	int dis = cx - c0;
	if ((dis ^ 0 && dis ^ 1) || b > 1 || dis == b) return puts("illegal"), 0;
	else if (b >= 0) return printf("the %s player won\n", b ? "second" : "first"), 0;
	else return puts(cx + c0 == 9 ? "draw" : dis ? "second" : "first"), 0;
}