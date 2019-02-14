//【P1151】子数整数 - 洛谷 - 80
#include <iostream>
#include <string>

int main() {
	int k;
	std::cin >> k;
	bool can = false;
	std::string num;
	for (int i = 10000; i <= 30000; ++i) {
		//num = std::to_string(i);
		//int sub1 = (num[0] - 48) * 100 + (num[1] - 48) * 10 + num[2] - 48;
		//int sub2 = (num[1] - 48) * 100 + (num[2] - 48) * 10 + num[3] - 48;
		//int sub3 = (num[2] - 48) * 100 + (num[3] - 48) * 10 + num[4] - 48;
		//if (sub1 % k == 0 && sub2 % k == 0 && sub3 % k == 0)
		//	std::cout << num << std::endl;
		int sub1 = (i / 10000) * 100 + (i / 1000 % 10) * 10 + (i / 100 % 10);
		int sub2 = (i / 1000 % 10) * 100 + (i / 100 % 10) * 10 + (i / 10 % 10);
		int sub3 = (i / 100 % 10) * 100 + (i / 10 % 10) * 10 + (i % 10);
		if (sub1 % k == 0 && sub2 % k == 0 && sub3 % k == 0) {
			std::cout << i << std::endl;
			can = true;
		}
	}
	if (!can) std::cout << "No" << std::endl;
}