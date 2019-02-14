//【P1551】亲戚 - 洛谷 - 0 
#include <iostream> 
#include <algorithm>

const int MAXNMP = 5000;

int fa[MAXNMP + 5];

int find(int x) {
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x]);
}

void work(int a, int b) {
	int aa = find(a), bb = find(b);
	fa[aa] = bb;
}

int main() {
	int n, m, p;
	std::cin >> n >> m >> p;
	for (int i = 1; i <= n; ++i)
		fa[i] = i;
	for (int i = 1; i <= m; ++i) {
		int mi, mj;
		std::cin >> mi >> mj;
		if (mi != mj)  {
			work(mi, mj);
		}
	}
	for (int i = 1; i <= p; ++i) {
		int pi, pj;
		std::cin >> pi >> pj;
		if (find(pi) == find(pj))
			std::cout << "Yes" << std::endl;
		else
			std::cout << "No" << std::endl;
	}
}