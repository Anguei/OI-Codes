//【P2256】一中校运会之百米跑 - 洛谷 - 0
#include <map>
#include <string>
#include <iostream>
#include <algorithm>

const int MAXN = 20000;
int fa[MAXN + 5];
std::map<std::string, int> map;

int find(int x) {
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}

void merge(std::string name1, std::string name2) {
	int f1 = find(map[name1]), f2 = find(map[name2]);
	fa[f1] = f2;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		std::string name;
		std::cin >> name;
		map[name] = i;
		fa[i] = i;
	}
	for (int i = 1; i <= m; ++i) {
		std::string name1, name2;
		std::cin >> name1 >> name2;
		merge(name1, name2);
	}
	int k;
	std::cin >> k;
	for (int i = 1; i <= k; ++i) {
		std::string name1, name2;
		std::cin >> name1 >> name2;
		if (find(map[name1]) == find(map[name2]))
			std::cout << "Yes." << std::endl;
		else
			std::cout << "No." << std::endl;
	}
}



namespace Second {
	const int MAXN = 20000;
	std::string fa[20000 + 10];
	std::map<std::string, int> map;

	inline int find(std::string name) {
		if (map[fa[map[name]]] == map[name])
			return map[name];
		return map[fa[map[name]]] = find(fa[map[name]]);
	}

	inline void merge(std::string name1, std::string name2) {
		int afa = find(name1), bfa = find(name2);
		fa[afa] = bfa;
	}

	int main() {
		int n, m;
		std::cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			std::string name;
			std::cin >> name;
			map[name] = map.size() + 1;
			fa[map[name]] = name;
		}
		for (int i = 0; i <= m; ++i) {
			std::string name1, name2;
			std::cin >> name1 >> name2;
			merge(name1, name2);
		}
		std::cin.get(); std::cin.get();
		int k;
		std::cin >> k;
		std::cout << k << std::endl;
		for (int i = 1; i <= k; ++i) {
			std::string name1, name2;
			std::cin >> name1 >> name2;
			std::cout << (fa[map[name1]] == fa[map[name2]] ? "Yes." : "No.") << std::endl;
		}
	}
}



namespace First {
	std::map<std::string, std::string> fa;

	inline std::string find(std::string name) {
		if (fa[name] == name)
			return name;
		return fa[name] = find(fa[name]);
	}

	inline void merge(std::string name1, std::string name2) {
		std::string faa = find(name1), fab = find(name2);
		fa[faa] = fab;
	}

	int main() {
		int n, m;
		std::cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			std::string name;
			std::cin >> name;
			fa[name] = name;
		}
		for (int i = 1; i <= m; ++i) {
			std::string name1, name2;
			std::cin >> name1 >> name2;
			merge(name1, name2);
		}
		int k;
		std::cin >> k;
		for (int i = 1; i <= k; ++i) {
			std::string name1, name2;
			std::cin >> name1 >> name2;
			if (fa[name1] == fa[name2])
				std::cout << "Yes." << std::endl;
			else
				std::cout << "No." << std::endl;
		}
		std::cout << "------------------------------------" << std::endl;
		for (auto &i : fa)
			std::cout << i.first << " " << i.second << std::endl;
	}
}