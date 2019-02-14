//【CF987B】High School Become Human - 洛谷 - Wa 
#include <cmath>
#include <iostream>
 
int main()
{
	double x, y;
	std::cin >> x >> y;
	double ansX = y * std::log(x);
	double ansY = x * std::log(y);
	char ans = 0;
	if (std::abs(ansX - ansY) < 1e-6) 
		ans = ';=';;
	else if (ansX > ansY)
		ans = ';>';;
	else if (ansX < ansY)
		ans = ';<';;
	std::cout << ans << std::endl;
}