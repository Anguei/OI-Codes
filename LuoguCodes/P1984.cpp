//【P1984】[SDOI2008]烧水问题 - 洛谷 - 0
#include <cstdio>
#include <iostream>
#include <iomanip>

int main() {
	int n;
	std::cin >> n;
	double now, ans;
	now = 420000.0 / n;
	for (int i = 1; i <= n; ++i) {
		ans += now;
		now *= (1 - 0.5 / static_cast<double>(i));
	}
	//std::cout << std::setprecision(2) << ans << std::endl;
	printf("%.2f\n", ans);
}