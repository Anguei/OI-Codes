//【P1087】FBI 树 - 洛谷 - 0 
#include <string>
#include <iostream> 
#include <algorithm>

std::string s;

void makeTree(int l, int r) {
	if (r > l) {
		makeTree(l, (l + r) / 2);
		makeTree((l + r) / 2 + 1, r);
	}
	bool B, I;
	B = I = true;
	for (int i = 0; i <= r - l; ++i) {
		if (s[l + i] - 48)
			B = false;
		else if (!s[l + i] - 48)
			I = false;
	}
	if (B)
		std::cout.put(66);
	else if (I)
		std::cout.put(';I';);
	else
		std::cout.put(';F';);
}

int main() {
	int n;
	std::cin >> n;
	std::cin >> s;
	
	makeTree(0, s.size() - 1);
}