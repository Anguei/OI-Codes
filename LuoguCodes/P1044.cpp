//【P1044】栈 - 洛谷 - 80
#include <iostream> 

int main () {
	int n;
	std::cin >> n;
	unsigned long long **a = new unsigned long long*[2 * n + 3];
	for (int i = 0; i < 2 * n + 3; ++i)
		a[i] = new unsigned long long[2 * n + 3];
	a[0][0] = 0, a[1][1] = 1, a[1][2] = 0;
	for (unsigned long long i = 2; i < 2 * n + 3; ++i) {
		for (unsigned long long j = 2; j <= i; ++j) {
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
	/*for (int i = 1; i < 2 * n + 3; ++i) {
		for (int j = 1; j <= i; ++j)
			std::cout << a[i][j] << " ";
		std::cout << std::endl;
	}*/
	std::cout << a[2 * n + 2][n + 2] / (n + 1);
}