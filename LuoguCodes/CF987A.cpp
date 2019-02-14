//【CF987A】Infinity Gauntlet - 洛谷 - Ac 
#include <map> 
#include <string>
#include <iostream>

int main()
{
	int n;
	std::cin >> n;
	int tot = 6;
	std::map<std::string, std::string> ans;
	
	ans["purple"] = "Power";
	ans["green"] = "Time";
	ans["blue"] = "Space";
	ans["orange"] = "Soul";
	ans["red"] = "Reality";
	ans["yellow"] = "Mind";	
	
	while (n--)
	{
		std::string tmp;
		std::cin >> tmp;
		ans[tmp] = "NULL";
		--tot;
	}
	
	std::cout << tot << std::endl;
	for (auto i : ans)
		if (i.second != "NULL")
			std::cout << i.second << std::endl;
}