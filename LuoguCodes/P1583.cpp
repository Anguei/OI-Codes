//【P1583】魔法照片 - 洛谷 - 0
#include <iostream>
#include <algorithm>

struct People {
	//int w, d, c;
	int w, id;
} *a;

inline bool cmp(People p1, People p2) {
	if (p1.w == p2.w)
		return p1.id < p2.id;
	return p1.w > p2.w;
}

int main() {
	int n, k;
	std::cin >> n >> k;
	a = new People[n + 1];
	int *e = new int[10 + 1];
	for (int i = 1; i <= 10; ++i) {
		std::cin >> e[i];
	}
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i].w;
		a[i].id = i;
	}
	std::sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; ++i) {
		a[i].w += e[((i - 1) % 10) + 1];
	}
	std::sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= k; ++i) {
		std::cout << a[i].id << " ";
	}
	std::cout << std::endl;
}