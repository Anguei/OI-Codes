//【P1320】压缩技术（续集版） - 洛谷 - 0
#include <stack>
#include <string>
#include <vector>
#include <iostream>

int main() {
	std::vector<std::string> vecs;
	std::string s;
	while (std::cin >> s)
		vecs.push_back(s);
	std::cout << vecs[0].length();
	s.clear();
	for (auto i : vecs)
		s += i;
	std::stack<bool> stk;
	bool yyf = false;
	for (int i = 0; i <= s.length(); ++i) {
		stk.push(s[i] - 48);
		if (yyf != s[i] - 48) {
			stk.pop();
			std::cout << " " << stk.size();
			while (!stk.empty())
				stk.pop();
			stk.push(s[i]);
			yyf = !yyf;
		}
	}
}