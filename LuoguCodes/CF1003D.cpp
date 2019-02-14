//【CF1003D】Coins and Queries - 洛谷 - Ac
#pragma GCC optimize(3)
#include <bits/stdc++.h>

int a[200005], b[33], c[33], pri[33];

int main() 
{
    std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, q;
    std::cin >> n >> q;
	for (int i = 1; i <= n; i++) 
    {
		std::cin >> a[i];
		int tmp = 0;
		while (a[i] > 1)
        {
			a[i] >>= 1;
			++tmp;
		}
		++pri[tmp + 1];
	}

    //std::sort(a.begin(), a.end(), std::greater<int>());

	while (q--)
    {
		int tmp;
		std::cin >> tmp;
		/*if (tmp & 1)
		{
			std::cout << -1 << std::endl;
			continue;
		}*/
		for (int i = 1; i <= 31; ++i)
            b[i] = static_cast<bool>((1 << i - 1) & tmp);

		memcpy(c, pri, sizeof(c));
		int ans = 0;
		b[0] = 0;

		for (int i = 31; i >= 1; --i)
        {
			if (!b[i])
				continue;     
            if (c[i] < b[i])
            {
                ans += c[i];
                b[i] -= c[i];
                b[i - 1] += b[i] * 2;
            }
            else
                ans += b[i];
		}
        
        std::cout << (b[0] ? -1 : ans) << std::endl;
		//std::cout << __builtin_popcount(b) << std::endl;
		/*int ans = 0, tot = 0, pos = 0;
		while (tot < b)
		{
			while (tot + a[pos] > b)
				++pos;
			tot += a[pos];
			++ans;
			if (pos == n - 1)
			{
				std::cout << -1 << std::endl;
				break;
			}
		}
		std::cout << ans << std::endl;*/
	}
}