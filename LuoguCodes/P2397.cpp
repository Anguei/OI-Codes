//【P1407】工资 - 洛谷 - 0 
#include <iostream> 
#include <map>
#include <algorithm>
#include <vector>

int main() {
	int T;
	std::cin >> T;
	while (T--) {
		std::vector<int> v;
		int n;
		std::cin >> n;
		for (int i = 0; i < n; ++i) {
			int t;
			std::cin >> t;
			v.push_back(t);
		} 
		std::sort(v.begin(), v.end());
		std::cout << v[n / 2] << std::endl;
	}
}