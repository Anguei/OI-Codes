#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x" = " << (x) << std::endl
#else
#define dbg(x) x
#endif

int read() {
    int res = 0, flag = 1; char ch = getchar();
    while (!isdigit(ch)) { if (ch == ';-';) flag = -1; ch = getchar(); }
    while (isdigit(ch)) res = res * 10 + ch - 48, ch = getchar();
    return res * flag;
}

void print(int x) {
    if (x < 0) putchar(';-';), x = -x;
    if (x > 9) print(x / 10);
    putchar(x % 10 + 48);
}

int n, m;
std::vector<int> a, b;

bool check(double mid) {
	double all = mid + m;
	double rest = all;
	rep(i, 1, n) {
		rest -= rest / double(a[i]);
		rest -= rest / double(a[n - i + 1]);
	}
	return rest >= 0;
}

int main() {
	n = read(), m = read();
	a.push_back(0); b.push_back(0);
	rep(i, 1, n) a.push_back(read()); rep(i, 1, n) b.push_back(read());
	rep(i, 1, n) if (a[i] == 1 || b[i] == 1) return std::cout << -1 << std::endl, 0;
	double now = m; 
	for (int i = n; i >= 1; --i) {
		int j = (i + 1 > n) ? 1 : i + 1;
		double k = now / (b[j] - 1);
		now += k;
		k = now / (a[i] - 1);
		now += k;
	}
	return std::cout << std::fixed << std::setprecision(10) << now - m << std::endl, 0;
	double l = 0, r = 1000000000;
	while (l < r) {
		double mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	if (l < 1000000000) std::cout << std::fixed << std::setprecision(10) << l << std::endl;
	else std::cout << -1 << std::endl;
}