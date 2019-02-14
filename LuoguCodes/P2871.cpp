//【P2871】[USACO07DEC]手链Charm Bracelet - 洛谷 - 100
#include <cstdio>
#include <iostream> 
#include <algorithm>

int f[12880 + 5];
int c[3402 + 5], w[3402 + 5];

inline int read() {
	register int flag = 1;
	register char ch = getchar();
	while (ch > ';9'; || ch <';0';) { if (ch == ';-';) { flag = -1; break; } ch = getchar(); }
	int ans = 0;
	while (ch >= ';0'; && ch <= ';9';) { ans = ans * 10 + ch - 48; ch = getchar(); }
	return ans;
}

int main() {
    register int n, m;
    n = read(); m = read(); //std::cin >> n >> m;
    for (register int i = 0; i ^ n; ++i) { c[i + 1] = read(); w[i + 1] = read(); } //std::cin >> c[i + 1] >> w[i + 1];
    for (register int i = 1; i <= n; ++i) for (register int j = m; j >= c[i]; --j) f[j] = std::max(f[j], f[j - c[i]] + w[i]);
    printf("%d\n", f[m]); //std::cout << f[m] << std::endl;
}