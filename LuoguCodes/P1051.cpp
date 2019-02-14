//【P1051】谁拿了最多奖学金 - 洛谷 - 100
#include <iostream> 
#include <algorithm>
#include <string>

struct Stu {
	std::string name;
	int score1, score2;
	char is1, is2;
	int lw;
	int money;
	int id;
	Stu(std::string name, int score1, int score2, char is1, char is2, int lw, int money) : name(name), score1(score1), score2(score2), is1(is1), is2(is2), lw(lw), money(money) {}
	Stu() {}
} *a;

inline bool cmp(Stu s1, Stu s2) {
	if (s1.money != s2.money)
		return s1.money > s2.money;
	return s1.id < s2.id;
}

int main() {
	int n;
	std::cin >> n;
	a = new Stu[n + 1];
	for (int i = 1; i <= n; ++i) {
		std::string name; int score1, score2; char is1, is2; int lw; int money = 0;
		std::cin >> name >> score1 >> score2 >> is1 >> is2 >> lw;
		if (score1 > 80 && lw >= 1) money += 8000;
		if (score1 > 85 && score2 > 80) money += 4000;
		if (score1 > 90) money += 2000;
		if (score1 > 85 && is2 == ';Y';) money += 1000;
		if (score2 > 80 && is1 == ';Y';) money += 850;
		a[i].name = name, a[i].money = money, a[i].id = i;
	}
	std::sort(a + 1, a + n + 1, cmp);
	std::cout << a[1].name << std::endl << a[1].money << std::endl;
	int tot = 0;
	for (int i = 1; i < n + 1; ++i) {
		tot += a[i].money;
	}
	std::cout << tot << std::endl;
}