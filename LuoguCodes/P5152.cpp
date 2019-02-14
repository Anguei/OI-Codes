// luogu-judger-enable-o2
// luogu-judger-enable-o2
#ifndef ONLINE_JUDGE
#define yyfLocal
#endif
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define fn "testdata"
#define ll long long
// #define int long long
#define fileIn freopen("testdata.in", "r", stdin)
#define fileOut freopen("testdata.out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x" = " << (x) << std::endl
#define logs(x) std::clog << (x) << std::endl
#else
#define dbg(x) 42
#define logs(x) 42
#endif

int read() { int x; std::cin >> x; return x; }
void print(int x) { std::cout << x; }

#define lowbit(x) ((x) & (-x))
#define fro(i, a, b, c) for (int i = (a); i <= (b); i += (c))
#define orf(i, a, b, c) for (int i = (a); i >= (b); i -= (c))
#define bl fro(i, x, n, lowbit(i)) fro(j, y, n, lowbit(j))
#define lb orf(i, x, 1, lowbit(i)) orf(j, y, 1, lowbit(j))
const int N = 3000 + 5;
int n, m, bit1[N][N], bit2[N][N], bit3[N][N], bit4[N][N];

struct Bit2D1 { void change(int x, int y, int dlt) { bl bit1[i][j] ^= dlt; } int sum(int x, int y) { int res = 0; lb res ^= bit1[i][j]; return res; } } b1;
struct Bit2D2 { void change(int x, int y, int dlt) { bl bit2[i][j] ^= dlt; } int sum(int x, int y) { int res = 0; lb res ^= bit2[i][j]; return res; } } b2;
struct Bit2D3 { void change(int x, int y, int dlt) { bl bit3[i][j] ^= dlt; } int sum(int x, int y) { int res = 0; lb res ^= bit3[i][j]; return res; } } b3;
struct Bit2D4 { void change(int x, int y, int dlt) { bl bit4[i][j] ^= dlt; } int sum(int x, int y) { int res = 0; lb res ^= bit4[i][j]; return res; } } b4;

void change(int px, int py, int dlt) { b1.change(px, py, dlt); if (px & 1) b2.change(px, py, dlt); if (py & 1) b3.change(px, py, dlt); if ((px * py) & 1) b4.change(px, py, dlt); }
void CHANGE(int x1, int y1, int x2, int y2, int dlt) { change(x2 + 1, y2 + 1, dlt); change(x2 + 1, y1, dlt); change(x1, y2 + 1, dlt); change(x1, y1, dlt); }
// void change(int px, int py, int dlt) { b1.change(px, py, dlt); if (px & 1) b2.change(px, py, dlt); if (py & 1) b3.change(px, py, dlt); if ((px * py) & 1) b4.change(px, py, dlt); }
// void CHANGE(int x1, int y1, int x2, int y2, int dlt) { change(x2 + 1, y2 + 1, dlt); change(x2 + 1, y1, dlt); change(x1, y2 + 1, dlt); change(x1, y1, dlt); }
int sum(int px, int py) { int res = 0; if (((px + 1) * (py + 1)) & 1) res ^= b1.sum(px, py); if ((py + 1) & 1) res ^= b2.sum(px, py); if ((px + 1) & 1) res ^= b3.sum(px, py); res ^= b4.sum(px, py); return res; }
int SUM(int x1, int y1, int x2, int y2) { int res = 0; res ^= sum(x2, y2); res ^= sum(x1 - 1, y2); res ^= sum(x2, y1 - 1); res ^= sum(x1 - 1, y1 - 1); return res; }
// int sum(int px, int py) { int res = 0; if (((px + 1) * (py + 1)) & 1) res ^= b1.sum(px, py); if ((py + 1) & 1) res ^= b2.sum(px, py); if ((px + 1) & 1) res ^= b3.sum(px, py); res ^= b4.sum(px, py); return res; }
// int SUM(int x1, int y1, int x2, int y2) { int res = 0; res ^= sum(x2, y2); res ^= sum(x1 - 1, y2); res ^= sum(x2, y1 - 1); res ^= sum(x1 - 1, y1 - 1); return res; }


void solution() {
	n = read(), m = read(); while (m--) {
		std::string opt; std::cin >> opt; int x1 = read(), y1 = read(), x2 = read(), y2 = read();
		if (opt[0] == ';P';) { int k = read(), res = 0; while (k--) { int a = read(), b = read(); if (b & 1) res ^= 1ll << (a - 1); } CHANGE(x1, y1, x2, y2, res); }
		if (opt[0] == ';Q';) { int out[35]; int res = SUM(x1, y1, x2, y2); rep(i, 0, 29) out[i] = (res & (1ll << i)) ? 2 : 1, print(out[i]); std::cout << std::endl; }
	}
}

signed main() {
#ifdef yyfLocal
	fileIn;
	// fileOut;
#else  
#ifndef ONLINE_JUDGE   
	freopen(fn".in", "r", stdin);
	freopen(fn".out", "w", stdout);
#endif
#endif
	logs("main.exe");
	solution();
}

// 别忘删掉 yyfLocal