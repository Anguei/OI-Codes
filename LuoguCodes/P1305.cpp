//【P1305】新二叉树 - 洛谷 - 0
#include <cctype>

#include <string>
#include <iostream>
#include <algorithm>

int n;
struct Node {
	char name, l, r;
} nodes[30];

void print(char name) {
	if (name == ';*';)
		return;
	for (int i = 1; i <= n; ++i)
		if (nodes[i].name == name) {
			std::cout << name;
			print(nodes[i].l);
			print(nodes[i].r);
		}
}

int main() {
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		std::cin >> nodes[i].name >> nodes[i].l >> nodes[i].r;
	print(nodes[1].name);
	std::cout << std::endl;
}