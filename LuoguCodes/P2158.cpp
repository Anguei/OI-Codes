//【P2158】[SDOI2008] 仪仗队 - 洛谷 - 0
#include <iostream>

int phi(int x) {
	int ret = 1;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            x /= i;
			ret *= i - 1;
            while (x % i == 0){
				x /= i;
				ret *= i;
			}
        }
    }
    if(x > 1)
		ret *= x - 1;
    return ret;
}

int main() {
	int n;
	std::cin >> n;
	if (n == 1) {
		std::cout << 0 << std::endl;
		return 0;
	}
	int ans = 0;
	for (int i = 3; i <= n; ++i)
		ans += phi(i - 1);
	std::cout << 2 * ans + 3 << std::endl;
}