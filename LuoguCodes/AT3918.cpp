//【AT3918】Infinite Coins - 洛谷 - Wa
#include <iostream> 

int main() {
	int n, m;
	std::cin >> n >> m;
	std::cout << (n % 500 <= m ? "Yes" : "No") << std::endl;
}