//【T17691】不开心的金明 - 洛谷 - 0
#include <iostream>
#include <algorithm>

using namespace std;

int *p, *v, *f;

int main() {
	int n, W;
	cin >> n >> W;
	p = new int[n + 1] , v = new int[n + 1];
	f = new int[W + 1];
	for (int i = 1; i <= n; ++i) {
		cin >> v[i] >> p[i];
	}
	for (int i = 0; i <= W; ++i) f[i] = 0;
	for (int i = 1; i <= n; ++i) {
		//for (int j = v[i]; j <= W; ++j) {
		for (int j = W; j >=  v[i]; --j) {
			f[j] = max(f[j], f[j - v[i]] + p[i]);
		}
	}
	cout << f[W] << endl;
}