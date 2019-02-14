#include <iostream>
#include <algorithm>

using namespace std;

int tt[200000 + 5];
bool f[1000000000 + 5];

int main() {
	int  n, t, maxt = 0;
	cin >> n >> t;
	for (int i = 0; i < n; ++i) {
		cin >> tt[i];
		maxt = max(maxt, tt[i]);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < t; ++j) {
			f[tt[i] + j] = true;
		}
	}
	int ans = 0;
	for (int i = 0; i < maxt + t + 1; ++i) {
		if (f[i]) ++ans;
	}
	cout << ans << endl;
}