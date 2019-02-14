#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
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

const int N = 25;
int T, n, ans, a, b;
int cnt[N], p[N];

void dfs(int rest, int depth) { 
	if (depth >= ans) return; // 剪枝
// ------------------------【顺子开始】---------------------------
	if (rest >= 1 * 5) { // 满足顺子的数量 
		int start = 0, end = 0; 
		rep(i, 1, 12) { // 顺子到不了「2」 
			if (cnt[i - 1] < 1) start = i; //更新顺子起点
			if (cnt[i] >= 1) end = i + 1; // 更新终点（左闭右开） 
			if (end - start >= 5) {
				rep(j, 5, end - start) { 
					start += j - 5;
					rep(k, start, end - 1) --cnt[k];
					dfs(rest - (end - start) * 1, depth + 1);
					rep(k, start, end - 1) ++cnt[k]; // 回溯 
					start -= j - 5; // 回溯 
				}
			}
		}
	}
	if (rest >= 2 * 3)  { // 对子顺子 
		int start = 0, end = 0;
		rep(i, 1, 12) {
			if (cnt[i - 1] < 2) start = i;
			if (cnt[i] >= 2) end = i + 1;
			if (end - start >= 3)  {
				rep(j, 3, end - start) {
					start += j - 3;
					rep(k, start, end - 1) cnt[k] -= 2;
					dfs(rest - ((end - start) << 1), depth + 1);
					rep(k, start, end - 1) cnt[k] += 2;
					start -= j - 3;
				}
			}
		}
	}
	if (rest >= 3 * 2) { // 三个顺子 
		int start = 0, end = 0;
		rep(i, 1, 12) {
			if (cnt[i - 1] < 3) start = i;
			if (cnt[i] >= 3) end = i + 1;
			if (end - start >= 2) {
				rep(j, 2, end - start) {
					start += j - 2;
					rep(k, start, end - 1) cnt[k] -= 3;
					dfs(rest - (end - start) * 3, depth + 1);
					rep(k, start, end - 1) cnt[k] += 3;
					start += j - 2;
				}
			}
		}
	}
// ------------------------【顺子完了】---------------------------
	int tmp = depth; 
	bool doubleKing = (cnt[14] && cnt[15]);
	memset(p, 0, sizeof p);
	rep(i, 1, 15) ++p[cnt[i]];
	if (p[4]) {
		tmp += p[4];
		if (p[2] >= (p[4] << 1)) p[2] -= (p[4] << 1);
		else {
			p[4] -= (p[2] >> 1);
			p[2] &= 1;
			if (p[1] >= (p[4] << 1)) p[1] -= (p[4] << 1);
			else p[1] &= 1;
		}
	}
	if (p[3]) {
		tmp += p[3];
		if (p[2] >= p[3]) p[2] -= p[3];
		else {
			p[3] -= p[2];
			p[2] = 0;
			if (p[1] >= p[3]) p[1] -= p[3];
			else p[1] = 0;
		}
	}
	if (p[2]) tmp += p[2];
	tmp += p[1];
	if (p[1] >= 2 && doubleKing) --tmp;
	ans = std::min(ans, tmp);
}

int main() {
#ifndef ONLINE_JUDGE 
	freopen("4325.in", "r", stdin);
	freopen("4325.out", "w", stdout);
#endif
	T = read(), n = read();
	while (T--) {		
		ans = n;
		memset(cnt, 0, sizeof cnt);		
		rep(i, 1, n) {
			a = read(), b = read();
			if (a == 0) ++cnt[13 + b]; // 大王小王 
			else if (a == 1) ++cnt[12]; // A 
			else if (a == 2) ++cnt[13]; // 2 
			else ++cnt[a - 2]; 
		}		
		dfs(n, 0);
		print(ans), puts("");
	}
}
/*
Input #1:
2 8
7 4
8 4
9 1
10 4
11 1
5 1
1 4
1 1
7 4
8 4
9 1
10 4
11 1
5 1
1 4
1 1
Output #1:
3
3

Input #2:
2 17
12 3
4 3 
2 3
5 4
10 2
3 3
12 2
0 1
1 3
10 1
6 2
12 1
11 3
5 2
12 4
2 2
7 2
12 3
4 3
2 3
5 4
10 2
3 3
12 2
0 1
1 3
10 1
6 2
12 1
11 3
5 2
12 4
2 2
7 2
Output #2:
6
6
*/