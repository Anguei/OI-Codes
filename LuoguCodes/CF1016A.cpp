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
#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x" = " << (x) << std::endl
#else
#define dbg(x) 
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

const int N = 200000 + 5;
int a[N], s[N];

signed main() {
	int n = read(), m = read();
	rep(i, 1, n) a[i] = read(), s[i] = s[i - 1] + a[i];
	int turned = 0;
	rep(i, 1, n) {
		s[i] -= turned * m;
		print(s[i] / m), putchar('; ';);
		turned += s[i] / m;
	}
	puts("");
}