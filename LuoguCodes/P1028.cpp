//【P1028】数的计算 - 洛谷 - 0
#include<iostream>

using namespace std;

int f[1005];

long long m(int s) {
	if (f[s] != -1) return f[s];
	int ans = 1;
	for (int i = 1; i <= s / 2; ++i)
		ans += m(i);
	f[s] = ans;
	return ans;
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		f[i] = -1;
	f[1] = 1;
	cout << m(n) << endl;
}