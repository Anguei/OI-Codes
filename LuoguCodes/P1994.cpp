//【P1994】有机物燃烧 - 洛谷 - 60
#include <cmath>
#include <cctype>

#include <string>
#include <sstream>
#include <iostream>

inline bool isInteger(double x) {
	return !(static_cast<int>(x) - x);
}

inline int addNum(const std::string& organicMatter, int x) {
	int num = 0;
	while (isdigit(organicMatter[x])) 
		num = num * 10 + organicMatter[x++] - 48;
	return num;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::string organicMatter;
	std::cin >> organicMatter;
	register int x = 0, y = 0, z = 0;
	
	for (register unsigned i = 0; i < organicMatter.size(); ++i) {
		switch (organicMatter[i]) {
			case ';C';:
				if (isdigit(organicMatter[i + 1]))
					x += addNum(organicMatter, i + 1);
				else
					x++;
				break;
			case ';H';:
				if (isdigit(organicMatter[i + 1]))
					y += addNum(organicMatter, i + 1);
				else
					y++;
				break;
			case ';O';:
				if (isdigit(organicMatter[i + 1]))
					z += addNum(organicMatter, i + 1);
				else
					z++;
				break;
			default:
				break;
		}
	}
	
	//std::cout << x << " " << y <<  " " << z << std::endl;
	 
	 register double num_co2 = x, num_h2o = y / 2.0, num_o2 = x + y / 4.0 - z / 2.0;
	 while (!isInteger(num_co2) || !isInteger(num_h2o) || !isInteger(num_o2)) {
	 	num_co2 *= 2;
	 	num_h2o *= 2;
	 	num_o2 *= 2;
	 }
	 std::cout << static_cast<int>(num_co2) << " " << static_cast<int>(num_h2o) << std::endl;
}
//CxHyOz+(x+y/4-z/2)O2-> xCO2＋(y/2)H2O
