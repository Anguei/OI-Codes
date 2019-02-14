//【CF784E】Twisted Circuit - 洛谷 - Uk
#include <iostream>

int main() {
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;
	int e, f, g, h, j, i, k;
	e = a ^ b;
	f = c | d;
	g = b & c;
	h = a ^ d;
	i = e & f;
	j = g | h;
	k = i ^ j;
	std::cout << k << std::endl;
}