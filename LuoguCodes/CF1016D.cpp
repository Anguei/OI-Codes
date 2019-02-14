#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define ll long long
#define int long long
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x" = " << (x) << std::endl
#else
#define dbg(x) ;
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

const int N = 100 + 5;
int a[N] , b[N];

signed main() {
	int n = read(), m = read(), x = 0, y = 0;
	rep(i, 0, n) x ^= (a[i] = read());
	rep(i, 0, m) y ^= (b[i] = read());
	if (x ^ y) return puts("NO"), 0;
	puts("YES");
	rep(i, 0, n) {
		if (i) {
			rep(j, 0, m) print(j ? 0 : a[i]), putchar('; ';); puts("");
		} else {
			rep(j, 0, m) {
				if (j) print(b[j]), putchar('; ';);
				else print(a[0] ^ x ^ b[0]), putchar('; ';);
			} puts("");
		}
	}
}