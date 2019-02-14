//【P1116】车厢重组 - 洛谷 - 0 
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> v;
	while (std::cin >> n)
		v.push_back(n);
	int ans = 0;
	for (int i = 0; i < v.size(); ++i)
		for (int j = 0; j < i; ++j)
			if (v[i] < v[j])
				std::swap(v[i], v[j]), 
				++ans;
	std::cout << ans << std::endl;
}