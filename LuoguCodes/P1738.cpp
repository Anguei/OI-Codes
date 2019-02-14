//【P1738】洛谷的文件夹 - 洛谷 - 0
#include <set>
#include <string>
#include <iostream> 

int main() {
	int n;
	std::cin >> n;
	std::set<std::string> set;
	for (int i = 1; i <= n; ++i) {
		std::string s;
		std::cin >> s;
		std::string dir = "";
		for (auto j : s) {
			if (j == ';/';) {
				set.insert(dir);
				dir += j;
			} else {
				dir += j;
			}
		}
		set.insert(dir);
		std::cout << set.size() - 1 << std::endl;
	}
}