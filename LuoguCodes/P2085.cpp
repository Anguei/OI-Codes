//【P2085】最小函数值 - 洛谷 - 0
#include <ios>
#include <set>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

inline int calc(int a, int b, int c, int x) {
	return a*x*x + b*x + c;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	//int *a = new int[n + 1], *b = new int[n + 1], *c = new int[n + 1];
	//int *f = new int[n + 1];
	std::priority_queue<int, std::vector<int>> q;
	std::vector<int> ans;
	int a, b, c;
	std::cin >> a >> b >> c;
	for (int i = 1; i <= m; ++i) {
		q.push(calc(a, b, c, i));
	}
	for (int i = 2; i <= n; i++) {
		std::cin >> a >> b >> c;
		for (int j = 1; j <= m; j++) {
			if (calc(a, b, c, j) < q.top()) {
				q.pop();
				q.push(calc(a, b, c, j));
			}
			else 
				break;
		}
	}
	for (int i = 1; i <= m; ++i) {
		ans.push_back(q.top());
		q.pop();
	}
	std::sort(ans.begin(), ans.end());
	for (auto i : ans) std::cout << i << " ";
	std::cout << std::endl;
	return 0;
}

















































/*//【P1631】序列合并 - 洛谷 - 100
#include <ios>
#include <set>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
	//std::ios::sync_with_stdio(false);
	int *a, *b, n;
	std::cin >> n;
	a = new int[n + 1], b = new int[n + 1];
	for (int i = 1; i <= n; ++i) std::cin >> a[i];
	for (int i = 1; i <= n; ++i) std::cin >> b[i];
	std::priority_queue<int, std::vector<int>> q;
	for (int i = 1; i <= n; ++i) {
		q.push(a[1] + b[i]);
	}
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (a[i] + b[j] < q.top()) {
				q.pop();
				q.push(a[i] + b[j]);
			}
			else break;
		}
	}
	std::vector<int> ans;
	std::set<int> s;
	for (int i = 0; i < n; ++i) {
		ans.push_back(q.top());
		//s.insert(q.top());
		q.pop();
	}
	//for (auto i : s) ans.push_back(i);
	std::sort(ans.begin(), ans.end());
	for (unsigned i = 0; i < ans.size(); ++i) std::cout << ans[i] << " ";
	std::cout << std::endl;
	return 0;
}*/