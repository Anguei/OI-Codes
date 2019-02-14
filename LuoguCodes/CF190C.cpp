//【CF190C】STL - 洛谷 - Ac
#include <string>
#include <iostream>

bool ok = true;
std::string s, ans;

void input() // 简单的递归 
{
	if (std::cin >> s)
	{
		if (s == "pair")
		{
			ans += "pair<";
			input();
			ans += ",";
			input();
			ans += ">";
		}
		else if (s == "int")
			ans += "int";
	}
	else // 输入不全（意外终止） 
		ok = false;
}

int main()
{
	std::getline(std::cin, s); // 无用的一行输入，吃掉它 
	input();
	if (!ok)
		ans = "Error occurred";
	std::getline(std::cin, s);
	if (s.size()) // 输入有多余 
		ans = "Error occurred";
	std::cout << ans << std::endl;
}