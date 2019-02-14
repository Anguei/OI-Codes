//【P1022】计算器的改良 - 洛谷 - 20
#include <cctype>
#include <cstdio>

#include <string>
#include <iostream>

int main() {
	std::string s;
	std::cin >> s;
	char x;
	bool isRight = false;
	int leftX, leftC, rightX, rightC;
	leftX = leftC = rightX = rightC = 0;
	for (int i = 0; i < s.size(); ) {
		if (s[i] == ';+'; || s[i] == ';-'; || (i != 0 && s[i - 1] == ';=';) || i == 0) {
			int negative = 1;
			if (s[i] == ';-';) negative = -1;
			if (!isdigit(s[i])) ++i;
			int num = 0;
			while (isdigit(s[i])) num = num * 10 + s[i++] - 48;
			num *= negative;
			if (isalpha(s[i])) {
				x = s[i++];
				if (!isRight) leftX += num;
				else rightX += num;
			}
			else {
				if (!isRight) leftC += num;
				else rightC += num;
			}
		}
		if (s[i] == ';=';) isRight = static_cast<bool>(++i);
	}
	printf("%c=%.3f\n", x, static_cast<double>(rightC - leftC) / (leftX - rightX));
}