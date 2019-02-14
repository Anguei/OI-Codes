//【CF978A】Remove Duplicates - 洛谷 - Ac 
#include <iostream> 

int a[1005], b[1005];
bool vis[1005];

int main()
{
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> a[i];
	int cnt = 0;
	for (int i = n; i; --i) 
	{
		if (vis[a[i]] == false) 
		{
			b[++cnt] = a[i];
			vis[a[i]] = true;
		}
	}
	std::cout << cnt << std::endl;
	for (int i = cnt; i; --i)
		std::cout << b[i] << " ";
	std::cout << std::endl;
}