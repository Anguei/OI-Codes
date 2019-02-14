#include <bits/stdc++.h>
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

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
int a[N], b[N], c[N], sumA = 0, sumB = 0;

signed main() {
    int n = read(), m = read();
    rep(i, 1, n) a[i] = read(), b[i] = read(), sumA += a[i], sumB += b[i];
    if (sumA <= m) return puts("0"), 0;
    if (sumB > m) return puts("-1"), 0;
    rep(i, 1, n) c[i] = a[i] - b[i];
    std::sort(c + 1, c + n + 1, std::greater<int>());
    int ans = 0;
    while (sumA > m) {
    	sumA -= c[++ans];
	}
	print(ans), puts("");
}