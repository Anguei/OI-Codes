//【P1165】日志分析 - 洛谷 - 49
#include <stack> 
#include <vector>
#include <iostream>
#include <algorithm>

const int kMaxN = 200000;
int a[kMaxN + 5] = { 0 };

int main() {
	int n;
	int o, x;
	std::cin >> n;
	int size = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> o;
		if (o == 0) {
			std::cin >> a[++size];
			a[size] = std::max(a[size - 1], a[size]);
		}
		if (o == 1) {
			if (size != 0) {
				a[size--] = 0;
			}
		}
		if (o == 2) {
			if (size == 0) {
				std::cout << 0 << std::endl;
				continue;
			}
			std::cout << a[size] << std::endl;
		}
	}
	//std::stack<int> s;
	//for (int i = 0; i < n; ++i) {
	//	std::cin >> o;
	//	if (o == 0) {
	//		std::cin >> x;
	//		s.push(x);
	//	}
	//	if (o == 1) {
	//		if (!s.empty())
	//			s.pop();
	//	}
	//	if (o == 2) {
	//		if (s.empty()) {
	//			std::cout << 0 << std::endl;
	//			continue; 
	//		}
	//		std::stack<int> s2(s);
	//		std::vector<int> v;
	//		while (!s2.empty()) {
	//			v.push_back(s2.top());
	//			s2.pop();
	//		}
	//		std::sort(v.begin(), v.end());
	//		std::cout << v.back() << std::endl;
	//	}
	//}
}