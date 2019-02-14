#include <bits/stdc++.h>
#define int long long
#define rep(i, a, b) for (int i = (a); i < (b); ++i)

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

const int N = 100000 + 5;
int a[N << 1];

int32_t main() {
	int n = read();
	if (n == 1) return puts("0"), 0;
	rep(i, 0, (n << 1)) a[i] = read();
	std::sort(a, a + (n << 1));
	int now = 0x3fffffff;
	rep(i, 1, n) now = std::min(now, a[i + n - 1] - a[i]);
	int ans = std::min((a[(n << 1) - 1] - a[0]) * (now), (a[n - 1] - a[0]) * (a[(n << 1) - 1] - a[n]));
	print(ans), puts("");
}