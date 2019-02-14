//【UVA11462】Age Sort - 洛谷 - Wa
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

int main() {
	//std::ios::sync_with_stdio(false);
	int n;
	std::cin >> n;
	while (n != 0) {
		//std::string s;
		//std::cin >> s;
		std::vector<int> v(n);
		for (int i = 0; i < n; ++i) 
			std::cin >> v[i];
		std::sort(v.begin(), v.end());
		for (int i = 0; i < n - 1; ++i)
			std::cout << v[i] << " ";
		std::cout << v.back() << std::endl;
		std::cin >> n;
	}
}