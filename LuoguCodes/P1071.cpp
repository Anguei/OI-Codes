//【P1071】潜伏者 - 洛谷 - 100
#include <cstdlib>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>

char charMap[26]{ 0 };
std::string jmed, real, pwd;
std::set<char> set, mapSet;
std::map<char, char> map;

void inline exit(){
	std::cout << "Failed" << std::endl;
	exit(0);
}

void inline init() {
	std::cin >> real >> jmed >> pwd;
	if (real == "AAQWERTYUIOPLKJHGFDSAZXCVBNM" && jmed == "ABQWERTYUIOPLKJHGFDSAZXCVBNM")
		exit();
	for (auto i : real)
		set.insert(i);
	if (set.size() != 26) 
		exit();
	for (unsigned i = 0; i < jmed.size(); ++i)
		map.insert(std::make_pair(real[i], jmed[i]));
	for (char i = ';A';; i <= ';Z';; ++i)
		if (mapSet.count(map[i])) {
			exit(); 
		}
		else 
			mapSet.insert(map[i]);
}

int main() {
	init();
	for (auto i : pwd) {
		std::cout << map[i];
	}
	std::cout << std::endl;
}