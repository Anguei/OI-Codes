//【P4325】[COCI2006-2007 Contest1] Modulo - 洛谷 - 0 
#include <set>
#include <iostream>

int main()
{
	std::set<int> set;
	for (int i = 0; i < 10; ++i)
	{
		int a;
		std::cin >> a;
		set.insert(a % 42);
	}
	std::cout << set.size() << std::endl;
}