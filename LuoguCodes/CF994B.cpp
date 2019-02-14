#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using ll = long long;

struct Knight
{
	ll p, c, ans, no;
} knight[100000 + 5];
ll sum[100000 + 5];

int main()
{
	std::ios::sync_with_stdio(false);
	int n, k;
	std::cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		knight[i].no = i;
	for (int i = 1; i <= n; ++i)
		std::cin >> knight[i].p;
	for (int i = 1; i <= n; ++i)
		std::cin >> knight[i].c;
	std::sort(knight + 1, knight + n + 1, [](const Knight &k1, const Knight &k2)
	{
		return k1.p < k2.p;	
	});
	std::priority_queue<ll, std::vector<ll>, std::greater<ll>> pq;
	for (int i = 1; i <= n; ++i)
	{
		if (i <= k)
		{
			pq.push(knight[i].c);
			sum[i] = sum[i - 1] + knight[i].c;
		}
		else if (k)
		{
			if (pq.top() < knight[i].c)
			{
				sum[i] = sum[i - 1] + knight[i].c - pq.top();
				pq.pop();
				pq.push(knight[i].c);
			}
			else
				sum[i] = sum[i - 1];
		}
	}
	for (int i = 1; i <= n; ++i)
		knight[i].ans = knight[i].c + sum[i - 1];
	std::sort(knight + 1, knight + n + 1, [](const Knight &k1, const Knight &k2)
	{
		return k1.no < k2.no;
	});
	for (int i = 1; i <= n; ++i)
		std::cout << knight[i].ans << " ";
	std::cout << std::endl;
}