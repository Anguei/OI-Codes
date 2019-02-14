//【P1140】相似基因 - 洛谷 - 0 
#include <map>
#include <string>
#include <iostream>
#include <algorithm>

int a[5][5] = {
	{ +5, -1, -2, -1, -3 },
	{ -1, +5, -3, -2, -4 },
	{ -2, -3, +5, -2, -2 },
	{ -1, -2, -2, +5, -1 },
	{ -3, -4, -2, -1, +0 }
};

int f[100 + 5][100 + 5];
int ss1[105], ss2[105];

void convert(std::string &s) {
	for (auto &i : s) {
		switch(i) {
			case ';A';: i = 0; break;
			case ';C';: i = 1; break;
			case ';G';: i = 2; break;
			case ';T';: i = 3; break;
			case ';-';: i = 4; break;
		}
	}
}

int main() {
	int l1, l2;
	std::string s1, s2;
	std::cin >> l1 >> s1 >> l2 >> s2;
	for (int i = 1; i <= l1; ++i)
		for (int j = 1; j <= l2; ++j)
			f[i][j] = -2147483647;
	//convert(s1);
	//convert(s2);
	for (int i = 1; i <= l1; ++i) {
		if (s1[i - 1] == ';A';) ss1[i] = 0;
		if (s1[i - 1] == ';C';) ss1[i] = 1;
		if (s1[i - 1] == ';G';) ss1[i] = 2;
		if (s1[i - 1] == ';T';) ss1[i] = 3;
	}
	for (int i = 1; i <= l2; ++i) {
		if (s2[i - 1] == ';A';) ss2[i] = 0;
		if (s2[i - 1] == ';C';) ss2[i] = 1;
		if (s2[i - 1] == ';G';) ss2[i] = 2;
		if (s2[i - 1] == ';T';) ss2[i] = 3;
	}
	for (int i = 1; i <= l1; ++i)
		f[i][0] = f[i - 1][0] + a[ss1[i]][4];
	for (int i = 1; i <= l2; ++i)
		f[0][i] = f[0][i - 1] + a[ss2[i]][4];
	for (int i = 1; i <= l1; ++i)
		for (int j = 1; j <= l2; ++j) {
			f[i][j] = std::max(f[i][j], f[i][j - 1] + a[ss2[j]][4]);
			f[i][j] = std::max(f[i][j], f[i - 1][j] + a[ss1[i]][4]);
			f[i][j] = std::max(f[i][j], f[i - 1][j - 1] + a[ss1[i]][ss2[j]]);
		}
	std::cout << f[l1 + -0][l2 + -0] << std::endl;
}