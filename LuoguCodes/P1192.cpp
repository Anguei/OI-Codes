//【P1192】台阶问题 - 洛谷 - 0
#include <iostream>
#include <algorithm>

int work(int n, int k) {
	int *a = new int[n];
	a[0] = a[1] = 1;
	int sum = 0;
	int i;
	for (i = 2; i < n; ++i) {
		a[i] = a[i - 2] + a[i - 1];
		if (a[i] > k) break;
		++sum;
	}
	return sum + work(n - i, k);
}

int main()  {
	const int MOD = 100003;
	int n, k;
	std::cin >> n >> k;
	//std::cout << work(n, k) << std::endl;
	int *f = new int[n + 1];
	for (int i = 0; i <= n; ++i)
		f[i] = 0;
	f[0] = f[1] = 1;
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= std::min(i, k); ++j) {
			if (j > k || j > i) break;
			f[i] += f[i - j];
			f[i] %= MOD;
		}
	}
	std::cout << f[n] << std::endl;
}