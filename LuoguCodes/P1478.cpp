//【P1478】陶陶摘苹果（升级版） - 洛谷 - 0
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<int> can;
	int n, s;
	cin >> n >> s;
	int a, b;
	cin >> a >> b;
	int *x = new int[n];
	int *y = new int[n];
	for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
	for (int i = 0; i < n; ++i) x[i] -= b;
	for (int i = 0; i < n; ++i) if (x[i] <= a) can.push_back(y[i]);
	sort(can.begin(), can.end());
	int ans = 0;
	while (s) {
		if (s - can[ans] >= 0) s -= can[ans], ++ans;
		else break;
	}
	cout << ans << endl;
}