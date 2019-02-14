//【P1334】瑞瑞的木板 - 洛谷 - 10
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

int main() {
	typedef long long ll;
	ll n;
	std::cin >> n;
	std::priority_queue<ll, std::vector<ll>, std::greater<ll>> q;
	for (register ll i = 1; i <= n; ++i) {
		ll t;
		std::cin >> t;
		q.push(t);
	}
	ll ans = 0;
	for (int i = 1; i <= n - 1; ++i) {
		ll t1 = q.top(); q.pop();
		ll t2 = q.top(); q.pop();
		ans += t1 + t2;;
		q.push(t1 + t2);
	}
	std::cout << ans << std::endl;
}