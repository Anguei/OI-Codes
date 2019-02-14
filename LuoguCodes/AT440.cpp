//【AT440】週末 - 洛谷 - Uk
#include <string>
#include <iostream>

int main() {
	std::string s;
	std::cin >> s;
	int ans = 0x7fffffff;
	if (s == "Saturday" || s == "Sunday")
		ans = 0;
	if (s == "Monday")
		ans = 5;
	if (s == "Tuesday")
		ans = 4;
	if (s == "Wednesday")
		ans = 3;
	if (s == "Thursday")
		ans = 2;
	if (s == "Friday")
		ans = 1;
		
	std::cout << ans << std::endl;
}