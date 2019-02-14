//【CF939B】Hamster Farm - 洛谷 - Re
#include <vector>
#include <iostream>

long long a[100000 + 5];

int main() {
	using ll = long long;
	ll n, k;
	std::cin >> n >> k;
	//std::vector<ll> a(n + 1);
	for (ll i = 1; i <= k; ++i)
		std::cin >> a[i];
	ll min = 1000000000000000005, what = 0;
	for (ll i = 1; i <= k; ++i)
		if (n % a[i] < min) {
			min = n % a[i];
			what = i;
		}
	std::cout << what << " " << n / a[what] << std::endl;
}