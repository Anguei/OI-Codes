//【P1107】最大整数 - 洛谷 - 0
#include <string>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>

inline bool cmp(std::string a, std::string b) { return a + b > b + a; }

int main() {
	int n;
	std::cin >> n;
	std::string s;
	std::priority_queue<std::string> q;
	std::vector<std::string> v;
	while (std::cin >> s)
		//q.push(s);
		v.push_back(s);
	std::sort(v.begin(), v.end(), cmp);
	//while (!q.empty()) {
	//	std::cout << q.top();
	//	q.pop();
	//}
	for (auto i : v)
		std::cout << i;
	std::cout << std::endl;
}