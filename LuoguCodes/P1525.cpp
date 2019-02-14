//【P1525】关押罪犯 - 洛谷 - 90
#pragma GCC optimize(2)

#include <iostream>
#include <algorithm>

const int kMaxN = 20000, kMaxM = 100000;
int fa1[kMaxN + 5], fa2[kMaxN + 5];
struct Data {
	int a, b, c;
} data[kMaxM + 5];

int find(int x) {
	if (fa1[x] == x)
		return x;
	return fa1[x] = find(fa1[x]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	fa1[b] = a;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		fa1[i] = i;
	int ans = 0;
	for (int i = 1; i <= m; ++i)
		std::cin >> data[i].a >> data[i].b >> data[i].c;
	std::sort(data + 1, data + m + 1, [](const Data &d1, const Data &d2) { return d1.c > d2.c; });
	for (int i = 1; i <= m; ++i) {
		if (find(data[i].a) == find(data[i].b)) {
			std::cout << data[i].c << std::endl;
			return 0;
		} else {
			if (!fa2[data[i].a])
				fa2[data[i].a] = data[i].b;
			else
				merge(fa2[data[i].a], data[i].b);
			if (!fa2[data[i].b])
				fa2[data[i].b] = data[i].a;
			else
				merge(fa2[data[i].b], data[i].a);
		}
	}
	std::cout << 0 << std::endl;
}

