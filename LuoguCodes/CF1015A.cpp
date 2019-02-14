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

int main() {
	int a[105] = { 0 };
	int n = read(), m = read();
	rep(i, 1, n) {
		int l = read(), r = read();
		rep(j, l, r) a[j]++;
	}
	int ans = 0;
	rep(i, 1, m) if (!a[i]) ++ans;
	print(ans), puts("");
	rep(i, 1, m) if (!a[i]) print(i), putchar('; ';); puts("");
}