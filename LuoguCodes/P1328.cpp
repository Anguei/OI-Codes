//【P1328】生活大爆炸版石头剪刀布 - 洛谷 - 0
#include <iostream>

int main() {
	int n, na, nb;
	std::cin >> n >> na >> nb;
	int a[na], b[nb];
	int ansa = 0, ansb = 0;
	for (int i = 0; i < na; ++i) std::cin >> a[i];
	for (int i = 0; i < nb; ++i) std::cin >> b[i];
	const int sheet[5][5] = {
		{ 0, 0, 1, 1, 0 },
		{ 1, 0, 0, 1, 0 },
		{ 0, 1, 0, 0, 1 },
		{ 0, 0, 1, 0, 1 },
		{ 1, 1, 0, 0, 0 }
	};
	for (int i = 0; i < n; ++i) {
		ansa += sheet[a[i % na]][b[i % nb]];
		ansb += sheet[b[i % nb]][a[i % na]];
	}
	std::cout << ansa << " " << ansb << std::endl;
}