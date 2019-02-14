// luogu-judger-enable-o2
//【P1068】分数线划定 - 洛谷 - 100
#pragma GCC optimize(3)

#include <cmath>

#include <vector>
#include <iostream>
#include <algorithm>

struct Contester{
	int k, s;
	Contester(int _k, int _s) : k(_k), s(_s) {}
	Contester() {}
};

int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<Contester> contesters, contestersFace;
	for (int i = 1; i <= n; ++i) {
		int _k, _s;
		std::cin >> _k >> _s;
		contesters.push_back(Contester(_k, _s));
	}
	std::sort(contesters.begin(), contesters.end(), [](const Contester &contester1, const Contester &contester2) {
		if (contester1.s != contester2.s)
			return contester1.s > contester2.s;
		else
			return contester1.k < contester2.k;
	});
	int faceTestScoreLine = contesters[std::floor(static_cast<double>(m) * 1.5) - 1].s;
	//std::clog << faceTestScoreLine << std::endl;
	for (const Contester &contester : contesters)
		if (contester.s >= faceTestScoreLine)
			contestersFace.push_back(contester);
	contesters = contestersFace;
	std::sort(contesters.begin(), contesters.end(), [](const Contester &contester1, const Contester &contester2) {
		if (contester1.s != contester2.s)
			return contester1.s > contester2.s;
		else
			return contester1.k < contester2.k;
	});
	std::cout << faceTestScoreLine << " " << contesters.size() << std::endl;
	for (const Contester &contester : contesters)
		std::cout << contester.k << " " << contester.s << std::endl;
}