// luogu-judger-enable-o2
//【P1628】合并序列 - 洛谷 - 100
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>

int main() {
	int n;
	std::cin >> n;
	std::string s;
	std::vector<std::string> v;
	while (std::cin >> s)
		v.push_back(s);
	std::string t = v.back();
	v.pop_back();
	std::priority_queue<std::string, std::vector<std::string>, std::greater<std::string>> q;
	for (auto i : v)
		if (i.substr(0, t.size()) == t)
			q.push(i);
	while (!q.empty()) {
		std::cout << q.top() << std::endl;
		q.pop();
	}
}