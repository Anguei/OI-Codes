//【P1865】A % B Problem - 洛谷 - 0
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

const std::string ansNo = "Crossing the line";
#define AN ansNo
const int MAXM = 1000000;

int f[MAXM + 5];
bool isNotPrimes[MAXM + 5];
#define INP isNotPrimes

int main() {
	int n, m;
	std::cin >> n >> m;
	INP[0] = INP[1] = true;
	int sqrtM = sqrt(m + 0.5);
	#define SM sqrtM
	for (register int i = 2; i <= SM; ++i)
		for (register int j = i * i; j <= m; j += i)
			INP[j] = true;
	for (register int i = 1; i <= m; ++i)
		f[i] = f[i - 1] + !INP[i];
	int l, r;
	for (int i = 1; i <= n; ++i) {
		std::cin >> l >> r;
		if (l < 1 || r > m) {
			std::cout << AN << std::endl;
			continue;
		}
		std::cout << f[r] - f[l - 1] << std::endl;
	}
}