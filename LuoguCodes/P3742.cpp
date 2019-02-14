//【P3742】umi的函数 - 洛谷 - 0 
#include <string>
#include <iostream> 
#include <algorithm>

int main() {
	int l;
	std::cin >> l;
	std::string x, y, z;
	std::cin >> x >> y;
	bool ok = true;
	for (register unsigned i = 0; i < x.size(); ++i) {
		if (y[i] > x[i]) ok = false;
	}
	if (ok)	 {
		std::cout << y << std::endl;
	}
	else {
		std::cout << -1 << std::endl;
	}
}