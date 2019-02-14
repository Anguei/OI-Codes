// luogu-judger-enable-o2
//【P2550】[AHOI2001] 彩票摇奖 - 洛谷 - 100
#include <map>
#include <set>
#include <iostream>

inline void insert(std::set<int> &set, int n = 7) {
	for (register int i = 0; i < 7; ++i) {
		register int tmp;
		std::cin >> tmp;
		set.insert(tmp);
	}
}

int main() {
    std::ios::sync_with_stdio(false);
	register int n;
	std::cin >> n;
	std::set<int> prize;
	insert(prize);
	std::map<int, int> info;
	for (register int i = 0; i < n; ++i) {
		std::set<int> buy;
		insert(buy);
		register int level = 7;
		for (register auto i : buy)
			if (prize.count(i))
				--level;
		++info[level];
	}
	for (register int i = 0; i < 7; ++i) 
		std::cout << info[i] << " ";
	std::cout << std::endl;
}