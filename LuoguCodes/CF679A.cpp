//【CF679A】Bear and Prime 100 - 洛谷 - Uk
#include <string>
#include <iostream>

const int primes[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 4, 9, 16, 25, 49};

int main() {
	//outPutPrimesArray();
	int times = 0;
	for (int i = 0; i < 20; ++i) {
		std::cout << primes[i] << std::endl;
		std::cout.flush();
		std::string s;
		std::cin >> s;
		if (s.front() == ';y';) 
			++times;
	}
	std::cout << (times > 1 ? "composite" : "prime") << std::endl;
}