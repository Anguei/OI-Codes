//【P1464】Function - 洛谷 - 0
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

typedef long long ll;

ll f[22][22][22];

inline ll w(ll a, ll b, ll c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	else if (a > 20 || b > 20 || c > 20) a = b = c = 20;
	else if (f[a][b][c] != -1) return f[a][b][c];
	else if (a < b && b < c) return f[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	return f[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main() {
	ll a, b, c;
	memset(f, -1, sizeof f);
	while (cin >> a >> b >> c && (a != -1 || b != -1 || c != -1))
		printf("w(%lld, %lld, %lld) = %d\n", a, b, c, w(a, b, c));
}