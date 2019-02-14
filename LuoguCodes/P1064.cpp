#include <iostream>
#include <algorithm>
using namespace std;
int v[61][3], w[61][3], ans[60000]; // 有改动
int main() {
	int n, m;
	int a, b, c, zn = 0;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		if (c == 0) {
			v[i][0] = a; w[i][0] = b; // 有改动
			continue;
		} else {
			if (v[c][1] == 0) // 有改动
			{
				v[c][1] = a; w[c][1] = b;
				continue;
			} else {
				v[c][2] = a; w[c][2] = b;
			}
		}
	}
	for (int i = 1; i <= m; i++) // 有改动
		for (int j = n; j >= v[i][0]; j--) {
			if (j >= v[i][0]) ans[j] = max(ans[j], ans[j - v[i][0]] + v[i][0] * w[i][0]);
			if (j >= v[i][0] + v[i][1]) ans[j] = max(ans[j], ans[j - v[i][0] - v[i][1]] + v[i][0] * w[i][0] + v[i][1] * w[i][1]);
			if (j >= v[i][0] + v[i][2]) ans[j] = max(ans[j], ans[j - v[i][0] - v[i][2]] + v[i][0] * w[i][0] + v[i][2] * w[i][2]);
			if (j >= v[i][0] + v[i][1] + v[i][2]) ans[j] = max(ans[j], ans[j - v[i][0] - v[i][2] - v[i][1]] + v[i][0] * w[i][0] + v[i][1] * w[i][1] + v[i][2] * w[i][2]);
		}

	cout << ans[n]; // 有改动
	return 0;
}