#include <iostream> 

int a[105];

int main()
{
	int n, k;
	std::cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i];
	int ans = 0;
	for (int i = 1; i <= n; ++i)
		if (a[i] <= k)
			++ans, a[i] = k + 1;
		else
			break;
	for (int i = n; i >= 1; --i)
		if (a[i] <= k)
			++ans, a[i] = k + 1;
		else
			break;
	std::cout << ans << std::endl;
}