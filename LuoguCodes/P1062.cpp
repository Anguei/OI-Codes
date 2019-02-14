//【P1062】数列 - 洛谷 - 0 
#include <cmath>

#include <stack>
#include <iostream>

int main() {
	int64_t k, n, ans = 0;
	std::cin >> k >> n;
	std::stack<int64_t> s;
	while (n) {
		s.push(n & 1);
		n /= 2;
	}
	while (!s.empty()) {
		ans += s.top() * std::pow(k, s.size() - 1);
		s.pop();
	}
	std::cout << ans << std::endl;
}