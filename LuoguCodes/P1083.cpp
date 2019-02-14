#include <cstdio>
#include <cctype>
#include <cstring>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

const int N = 1000000 + 5, M = 1000000 + 5;

int r[N], d[M], s[M], t[M], sum[N], need[N];

int read() {
	int res = 0; char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) { res = res * 10 + ch - 48; ch = getchar(); }
	return res;
}

int main() {
	int n = read(), m = read(); int L = 1, R = m;
	rep(i, 1, n) r[i] = read();
	rep(i, 1, m) d[i] = read(), s[i] = read(), t[i] = read();
	auto check = [n](int x) {
		memset(sum, 0, sizeof sum);
		rep(i, 1, x) sum[s[i]] += d[i], sum[t[i] + 1] -= d[i];
		rep(i, 1, n) if ((need[i] = need[i - 1] + sum[i]) > r[i]) return false;
		return true;
	};
	if (check(m)) return puts("0"), 0;
	while (L < R) {
		int mid = (L + R) >> 1;
		if (check(mid)) L = mid + 1;
		else R = mid;
	}
	printf("-1\n%d", L);
}