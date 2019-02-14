//【P1146】硬币翻转 - 洛谷 - 0 
#include <iostream> 

int main() {
	int n;
	std::cin >> n;
	std::cout << n << std::endl;
	bool *a = new bool[n + 1];
	for (int i = 0; i <= n; ++i)
		a[i] = false;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i != j) {
				a[j] = !a[j];
			}
			std::cout << a[j];
		}
		std::cout << std::endl;
	}
}