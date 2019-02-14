#include <cmath>
#include <iostream>
#include <algorithm>

int main()
{
	double v, thita, pi = 3.1415926535, g = 10;
	std::cin >> v >> thita;
	double vxt = v * sin(thita);
	double vyt = v * cos(thita); 
	double t = vyt / g;
	double xxt = vxt * t;
	double xyt = 0.5 * vyt * t;
	std::cout << xxt << " " << xyt << std::endl;
}
