//【P1420】最长连号 - 洛谷 - 0 
#include <iostream> 
#include <algorithm>

int a[10005], f[10005];

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	f[0] = 1;
	for (int i = 1; i < n; ++i) {
		if (a[i] - a[i - 1] == 1)
			f[i] = f[i - 1] + 1;
		else
			f[i] = 1;
	}
	std::sort(f, f + n, std::greater<int>());
	std::cout << f[0] << std::endl;
}