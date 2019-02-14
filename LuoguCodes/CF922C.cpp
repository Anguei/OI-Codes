//【CF922C】Cave Painting - 洛谷 - Wa
//#include <set>
#include <iostream>

using ll = long long;

int main() {
	ll n, k;
	std::cin >> n >> k;
	//std::set<ll> set;
	for (ll i = 1; i <= k; ++i) {
		if (n % i != i - 1) {
			std::cout << "No" << std::endl;
			return 0;
		}
		//set.insert(n % i);
	}
	//std::cout << (k == set.size() ? "Yes" : "No") << std::endl;
	std::cout << "Yes" << std::endl;
}