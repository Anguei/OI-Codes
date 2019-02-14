//【P4279】[SHOI2008] 小约翰的游戏 - 洛谷 - 0
#include <iostream>

int main()
{
	int T;
	std::cin >> T;
	
	while (T--)
	{
		int n;
		std::cin >> n;
		int sum = 0;
		int ok = false;
		
		for (int i = 0; i < n; ++i)
		{
			int tmp;
			std::cin >> tmp;
			sum += tmp;
			ok ^= tmp;
		}
		
		if (sum == n)
			std::cout << (sum & 1 ? "Brother" : "John") << std::endl;
		else
			std::cout << (ok ? "John" : "Brother") << std::endl;
	}
}