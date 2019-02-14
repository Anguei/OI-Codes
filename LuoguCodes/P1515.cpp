//【P1515】旅行 - 洛谷 - 0 
#include <vector>
#include <iostream> 
#include <algorithm>

int main() {
	int a, b, n;
	std::cin >> a >> b >> n;
	std::vector<int> vec;
	void init(std::vector<int> &vec);
	init(vec);
	while (n--) {
		int t;
		std::cin >> t;
		vec.push_back(t);
	}
	std::sort(vec.begin(), vec.end());
	std::vector<int> ans(vec.size(), 0);
	//for (auto i : ans)std::cout << i << std::endl;
	ans[0] = 1;
	for (int i = 1; i < vec.size(); ++i) {
		for (int j = 0; j < i; ++j) {
			int dis = vec[i] - vec[j];
			if (dis >= a && dis <= b) {
				ans[i] += ans[j];
			}
		}
	}
	std::cout << ans.back() << std::endl;
}

void init(std::vector<int> &vec) {
	vec.push_back(0);
	vec.push_back(990);
	vec.push_back(1010);
	vec.push_back(1970);
	vec.push_back(2030);
	vec.push_back(2940);
	vec.push_back(3060);
	vec.push_back(3930);
	vec.push_back(4060);
	vec.push_back(4970);
	vec.push_back(5030);
	vec.push_back(5990);
	vec.push_back(6010);
	vec.push_back(7000);
}