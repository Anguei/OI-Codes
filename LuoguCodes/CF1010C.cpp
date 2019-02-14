#include <bits/stdc++.h>

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
	int n = read(), k = read(); int a, b = k;
	for (int i = 0; i < n; ++i) a = read(), b = std::__gcd(a, b);
	print(k / b), puts("");
	for(int i = 0; i < k; i += b) print(i), putchar('; ';); puts("");
}