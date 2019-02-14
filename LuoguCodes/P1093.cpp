//【P1093】奖学金 - 洛谷 - 0
#include <iostream>
#include <algorithm>

struct Stu {
	int id;
	int yw, sx, yy, tot;
} *a;

inline bool cmp(Stu s1, Stu s2) {
	if (s1.tot == s2.tot) {
		if (s1.yw == s2.yw) {
			return s1.id < s2.id;
		}
		else {
			return s1.yw > s2.yw;
		}
	}
	else {
		return s1.tot > s2.tot;
	}
}

int main() {
	int n;
	std::cin >> n;
	a = new Stu[n + 1];
	for (int i = 1; i < n + 1; ++i) {
		std::cin >> a[i].yw >> a[i].sx >> a[i].yy;
		a[i].tot = a[i].yw + a[i].sx + a[i].yy;
		a[i].id = i;
	}
	std::sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= 5; ++i) {
		std::cout << a[i].id << " " << a[i].tot << std::endl;
	}
	return 0;
}