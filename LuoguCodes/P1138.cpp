//【P1138】第k小整数 - 洛谷 - 0 
#include <iostream> 
#include <queue>
#include <vector>
#include <set>

int main() {
	int n, k;
	std::cin >> n >> k;
	int a;
	std::priority_queue<int, std::vector<int>, std::greater<int>> q;
	std::set<int> s;
	while (std::cin >> n)
		s.insert(n);
	for (auto &i : s)
		q.push(i);
	if (k > q.size()) {
		std::cout << "NO RESULT" << std::endl;
		return 0;
	}
	//while (!q.empty()) {
	//	std::cout << q.top() << " ";
	//	q.pop();
	//}
	for (int i = 0; i < k - 1; ++i) 
		q.pop();
	std::cout << q.top() << std::endl;
	
}