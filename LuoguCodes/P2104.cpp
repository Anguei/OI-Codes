//【P2104】二进制 - 洛谷 - 70
#include <vector>
#include <string>
#include <iostream>

int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> num;
	char ch;
	for (int i = 1; i <= n; ++i) {
		std::cin >> ch;
		num.push_back(ch - 48);
	}
	std::string oper;
	std::cin >> oper;
	
	for (const auto &i : oper)
		if (i == ';+';) {
			int j = num.size() - 1;
			++num[j];
			while (num[j] == 2) {
				num[j] = 0;
				++num[--j];
			}
		}
		else if (i == ';-';) {
			int j = num.size() - 1;
			if (num[j] == 1)
				--num[j];
			else {
				while (num[j] == 0)
					num[j--] = 1;
				num[j] = 0;
			}
		}
		else if (i == ';*';)
			num.push_back(0);
		else if(i == ';/';)
			num.pop_back();
			
	for (int i = 0; i < num.size(); ++i)
		std::cout << num[i];
	std::cout << std::endl;
}