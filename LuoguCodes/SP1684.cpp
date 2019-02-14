#include <cmath>
#include <iostream>
#include <algorithm>

const int N = 100000 + 5;

int a[N], p[N], s[N], e[N], max[N][18];
int n, q, cnt;

int main()
{
	//freopen("testdata.txt", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	while (std::cin >> n && n)
	{
		std::cin >> q;
		a[0] = -0x3f3f3f3f;
		cnt = 0;
		for (int i = 1; i <= n; ++i)
		{
			std::cin >> a[i];
			{
				if (a[i] ^ a[i - 1])
				{
					p[i] = ++cnt;
					s[cnt] = e[cnt] = i;
				}
				else
				{
					p[i] = cnt;
					++e[cnt];
				}
			}
		}
		for (int i = 1; i <= cnt; ++i)
			max[i][0] = e[i] - s[i] + 1;
		for (int j = 1; (1 << j) <= cnt; ++j)
			for (int i = 1; i + (1 << j) <= n; ++i)
				max[i][j] = std::max(max[i][j - 1], max[i + (1 << (j - 1))][j - 1]);
		while (q--)
		{
			int l, r, ans;
			std::cin >> l >> r;
			int x = p[l], y = p[r];
			if (y - x == 0)
				ans = r - l + 1;
			else if (y - x == 1)
				ans = std::max(e[x] - l + 1, r - s[y] + 1);
			else if (y - x > 1)
			{
				int L = x + 1, R = y - 1;
				int k = log(R - L + 1) / log(2);
				int rmq = std::max(max[L][k], max[R - (1 << k) + 1][k]);
				ans = std::max(std::max(e[x] - l + 1, r - s[y] + 1), rmq);
			}
			/*switch (y - x)
			{
			case 0:
				ans	= r - l + 1;
				break;
			case 1:
				ans = std::max(e[x] - l + 1, r - s[y] + 1);
				break;
			default:
				int L = x + 1, R = y - 1;
				int k = log(R - L + 1) / log(2);
				int rmq = std::max(max[L][k], max[R - (1 << k) + 1][k]);
				ans = std::max(std::max(e[x] - l + 1, r - s[y] + 1), rmq);
				break;
			}*/
			std::cout << ans << std::endl;
		}
	}
	/*int n, q;
	std::cin >> n >> q;
	int last = 0, cnt = 0, tot = 0;
	for (int i = 1; i <= n; ++i)
	{
		int now;
		std::cin >> now;
		if (i == 1)
			last = now;
		if (now == last)
		{
			s[tot] = i;
			++cnt;
		}
		else
		{
			e[tot] = i;
			a[++tot] = cnt;
		}
		p[i] = tot;
		last = now;
	}
	for (int i = 1; i <= tot; ++i)
		max[i][0] = a[i];
	for (int j = 1; (1 << j) <= tot; ++j)
		for (int i = 1; i + (1 << j) - 1 <= tot; ++i)
			max[i][j] = std::max(max[i][j - 1], max[i + (1 << (j - 1))][j - 1]);
	auto rmq = [](int l, int r)
	{
		int k = log(r - l + 1) / log(2);
		return std::max(max[l][k], max[r - (1 << k) + 1][k]);
	};
	while (q--)
	{
		int l, r, ans;
		std::cin >> l >> r;
		int x = p[l], y = p[r];
		if (x == y)
			ans = r - l + 1;
		else if (y - x == 1)
			ans = std::max(e[x] - l + 1, r - s[y] + 1);
		else if (y - x > 1)
			std::max(std::max(e[x] - l + 1, r - s[y] + 1), rmq(x + 1, y - 1));
		std::cout << ans << std::endl;
	}*/
}