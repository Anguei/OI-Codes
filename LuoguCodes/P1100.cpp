//【P1100】高低位交换 - 洛谷 - 0
#include <iostream> 

int main() {
	unsigned long long n;
	std::cin >> n;
	std::cout << ((n & 0x0000ffff) << 16 | (n & 0xffff0000) >> 16) << std::endl;
}