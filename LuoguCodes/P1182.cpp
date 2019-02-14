#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
#define ll long long
#define int long long
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

const int N = 100000 + 5;
int n, m, l = 0, r = 0;
int a[N];

bool check(int x) {
	int tot = 0, cnt = 0;
	rep(i, 1, n) if (tot + a[i] <= x) tot += a[i];
	else tot = a[i], ++cnt; // 割一段 
	return cnt >= m;
}

signed main() {
	n = read(), m = read();
	rep(i, 1, n) a[i] = read(), l = std::max(l, a[i]), r += a[i];;
	//std::sort(a + 1, a + n + 1); // 不能排序。。。 
	//int l = a[n], r = std::accumulate(a + 1, a + n + 1, 0);
	while (l <= r) { // 对长度和进行二分 
		int mid = (l + r) >> 1;
		if (check(mid)) l = mid + 1;
		else r = mid - 1;
	}
	print(l), puts("");
}