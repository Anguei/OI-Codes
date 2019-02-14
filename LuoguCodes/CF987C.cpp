#include <limits>
#include <iostream>
#include <algorithm>

using ll = long long;

const int kMaxN = 3000;
const ll kInf = std::numeric_limits<ll>::max() / 2;

ll s[kMaxN + 5], c[kMaxN + 5];

int main()
{
	//std::clog << kInf << std::endl;
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> s[i];
	for (int i = 1; i <= n; ++i)
		std::cin >> c[i];
	
	ll min = kInf;
	for (int i = 2; i < n; ++i)
	{ 
		ll left, right;
		left = right = kInf; 
		for (int j = 1; j < i; ++j)
			if (s[j] < s[i])
				left = std::min(left, c[j]);
		for (int j = i + 1; j <= n; ++j) 
			if (s[i] < s[j])
				right = std::min(right, c[j]);
		min = std::min(min, left + c[i] + right);
	} 
	std::cout << (min == kInf ? -1 : min) << std::endl;
}