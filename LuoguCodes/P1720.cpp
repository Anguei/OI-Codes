#include <cstdio>
#include <iostream> 
#include <iomanip>
#include <limits>
#include <cmath>

#define g5 sqrt(5) 

double f(int n) {
	double v1 = (1 + g5) / 2;
	double v2 = (1 - g5) / 2;
	double v11 = pow(v1, n);
	double v22 = pow(v2, n);
	double ret = (v11 - v22) / g5;
	return ret;
}

int main() {
	int n;
	std::cin >> n;
	//6
	//std::setprecision(2);
	//std::cout << f(n) << std::endl;
	//std::cout << std::setprecision(2) << f(n) << std::endl;
	printf("%.2f\n", f(n));
}