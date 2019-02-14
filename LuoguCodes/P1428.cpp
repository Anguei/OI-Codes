//【P1428】小鱼比可爱 - 洛谷 - 0
#include <iostream>
#include <algorithm>

int main()  {
	int n;
	std::cin >> n;
	int *a = new int[n];
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	int *b = new int[n];
	for (int i = 0; i < n; ++i) {
		b[i] = 0;
		for (int j = 0; j < i; ++j) {
			if (a[j] < a[i])
				++b[i];
		}
	}
	for (int i = 0; i < n; ++i) {
		std::cout << b[i] << " ";
	}
	std::cout << std::endl;
}