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
#include <numeric>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define fn "task"
#define ll long long
#define int long long
#define pc(x) putchar(x)
#define fileIn freopen("testdata.in", "r", stdin)
#define fileOut freopen("testdata.out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x" = " << (x) << std::endl
#define logs(x) std::clog << (x) << std::endl
#else
#define dbg(x) 42
#define logs(x) 42
#endif

char map[16][16];
unsigned table[16][16];
std::string s[16];
int filled = 0;

void fill (int i, int j, int a) {
    ++filled;
    map[i][j] = a;
    rep(k, 0, 16) table[i][k] |= (1 << (a - 1)), table[k][j] |= (1 << (a - 1));
    int r = (int)(i / 4) * 4, c = (int)(j / 4) * 4;
    rep(k, 0, 4) rep(m, 0, 4) table[r + k][c + m] |= (1 << (a - 1));
}

bool search() {
    int r1, r2, t0;
    char tMap[16][16];
    unsigned tTable[16][16]; int tFilled = 0;
    if (filled == 256) return true;
    rep(i, 0, 16) rep(j, 0, 16) {
        if (map[i][j]) continue;
        int r = -1;
        rep(k, 0, 16) if (((table[i][j] & (1 << k)) == 0) && r == -1) r = k; else if (((table[i][j] & (1 << k)) == 0) && r != -1) { r = -2; break; } 
        if (r == -1) return false; else if (r != -2) fill(i, j, r + 1);
    }
    rep(i, 0, 16) rep(k, 0, 16) {
        int r = -1;
        rep(j, 0, 16) {
            if (map[i][j] == k + 1) { r = -2; break; } if (map[i][j]) continue;
            if (((table[i][j] & (1 << k)) == 0) && r == -1) r = j; else if (((table[i][j] & (1 << k)) == 0) && r != -1) { r = -2; break; }
        }
        if (r == -1) return false; else if (r != -2) fill(i, r, k + 1);
    }
    rep(j, 0, 16) rep(k, 0, 16) {
        int r = -1;
        rep(i, 0, 16) {
            if (map[i][j] == k + 1) { r = -2; break; } if (map[i][j]) continue;
            if (((table[i][j] & (1 << k)) == 0) && r == -1) r = i; else if (((table[i][j] & (1 << k)) == 0) && r != -1) { r = -2; break; }
        }
        if (r == -1) return false; else if (r != -2) fill(r, j, k + 1);
    }
    for (int r = 0; r < 16; r += 4) for (int c = 0; c < 16; c += 4) rep(k, 0, 16) {
        r1 = -1, r2 = -1;
        rep(i, 0, 4) rep(j, 0, 4) {
            if (map[r + i][c + j] == k + 1) { r1 = r2 = -2; goto outerloop1; } if (map[r + i][c + j]) continue;
            if (((table[r + i][c + j] & (1 << k)) == 0) && r1 == -1) r1 = r + i, r2 = c + j; else if (((table[r + i][c + j] & (1 << k)) == 0) && r1 != -1) { r1 = r2 = -2; goto outerloop1; }
        }
        outerloop1:
        if (r1 == -1) return false; else if (r1 != -2) fill(r1, r2, k + 1);
    }
    if (filled == 256) return true;
    rep(i, 0, 16) rep(j, 0, 16) tMap[i][j] = map[i][j], tTable[i][j] = table[i][j]; tFilled = filled;
    t0 = 256;
    per(i, 15, 0) per(j, 15, 0) {
        if (map[i][j]) continue;
        int t = 0;
        rep(k, 0, 16) { if ((table[i][j] & (1 << k)) == 0) t++; if (t >= t0) break; }
        if (t < t0) { t0 = t; r1 = i, r2 = j; }
    }
    rep(m, 0, 16) {
        if ((table[r1][r2] & (1 << m)) == 0) {
            fill(r1, r2, m + 1);
            if (search()) return true;
            else { rep(i, 0, 16) rep(j, 0, 16) map[i][j] = tMap[i][j], table[i][j] = tTable[i][j]; filled = tFilled; }
        }
    }
    return false;
}

void solution() {
    filled = 0;
    memset(map, 0, sizeof map);
    memset(table, 0, sizeof table);
    rep(i, 0, 16) {
        std::cin >> s[i];
        rep(j, 0, 16) {
            char a = s[i][j];
            if (a == ';-';) continue;
            else fill(i, j, a - 64);
        }
    }
    search();
    rep(i, 0, 16) { rep(j, 0, 16) std::cout << static_cast<char>(map[i][j] + 64); std::cout << std::endl; }
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
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    int T; std::cin >> T; while (T--) solution(), std::cout.put(';\n';);
}