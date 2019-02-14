#include <limits>
#include <iostream>
#include <algorithm>

const int kMaxN = 50, kMaxM = 50;
long long a[kMaxN + 5], b[kMaxM + 5];

int main() {
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i];
	for (int i = 1; i <= m; ++i)
		std::cin >> b[i];
	long long ans = std::numeric_limits<long long>::max();
	for (int i = 1; i <= n; ++i) {
		long long t_ans = std::numeric_limits<long long>::min();
		for (int j = 1; j <= n; ++j) 
			if (i == j)
				continue;
			else
				for (int k = 1; k <= m; ++k)
					t_ans = std::max(t_ans, a[j] * b[k]);
		//std::clog << t_ans << std::endl;
		ans = std::min(ans, t_ans);
	}
	std::cout << ans << std::endl;
}