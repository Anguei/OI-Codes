#include <cstring>
#include <iostream>
#include <algorithm>

const int N = 10000 + 5;

bool prime[N];
int ans[N];

int main()
{
	memset(prime, 1, sizeof prime);
	prime[0] = prime[1] = false;
	for (int i = 2; i <= N; ++i)
		for (int j = i * i; j <= N; j += i)
			prime[j] = false;
	int n;
	std::cin >> n;
	for (int i = 2; i <= n; ++i)
		for (int j = 2, ii= i; j <= i; ++j)
			while (ii % j == 0)
				++ans[j], ii /= j;
	for (int i = 2; i <= n; ++i)
		if (ans[i])
			std::cout << i << " " << ans[i] << std::endl;
}