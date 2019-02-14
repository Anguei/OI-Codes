//【P3367】【模板】并查集 - 洛谷 - 70
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int find(int x, int *fa) {
	if (fa[x] == x)
		return x;
	return fa[x] = find(fa[x], fa);
}

void work(int a, int b, int *fa) {
	int faa = find(a, fa), fb = find(b, fa);
	fa[faa] = fb;
}

int main() {
	int n, m;
	cin >> n >> m;
	++m;
	int *z = new int[m],
		*x = new int[m],
		*y = new int[m],
		*fa = new int[m],
		*s1 = new int[m],
		*s2 = new int[m];
	--m;
	for (int i = 1; i <= n; ++i)
		fa[i] = i;
	for (int i = 1; i <= m; ++i) {
		cin >> z[i] >> x[i] >> y[i];
		s1[i] = find(x[i], fa);
		s2[i] = find(y[i], fa);
	}
	for (int i = 1; i <= m; ++i) {
		switch (z[i]) {
		case 1: if (s1[i] != s2[i]) work(s1[i], s2[i], fa); break;
		case 2:if (find(x[i], fa) == find(y[i], fa)) cout << "Y" << endl; else cout << "N" << endl; break;
		default:break;
		}
	}
}