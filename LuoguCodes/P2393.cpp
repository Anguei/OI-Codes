//【P2393】yyy loves Maths II - 洛谷 - 70
#include <cstdio>

#include <iomanip>
#include <iostream>

int main() {
	long double in, out = 0.0l;
	while (std::scanf("%Lf", &in) != EOF)
		out = out + in * 1000000;
	std::printf("%.5Lf", out / 1000000);
	
}