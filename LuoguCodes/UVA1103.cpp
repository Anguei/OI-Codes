#include <cctype>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <numeric>
#include <utility>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#define _ (0)
#define ll long long
#define int long long
#define pc(x) putchar(x)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, b, a) for (int i = (b); i >= (a); --i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x " = " << (x) << std::endl
#else
#define dbg(x) x
#endif

const int N = 200 + 5;
int n, m;
int map[N][N];
char str[N];
const int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
const int convert[] = { ';W';, ';A';, ';K';, ';J';, ';S';, ';D'; };
const int hex[] = { 10, 11, 12, 13, 14, 15 };
std::map<char, int> ans;

void clear() { ans.clear(); memset(map, 0, sizeof map); }

void input() {    
    rep(i, 1, n) {
        scanf("%s", str + 1);
        rep(j, 1, m) {
            int num = isdigit(str[j]) ? str[j] - 48 : hex[str[j] - 97];
            if (num >= 8) map[i][((j - 1) << 2) + 1] = 1, num -= 8;
            if (num >= 4) map[i][((j - 1) << 2) + 2] = 1, num -= 4;
            if (num >= 2) map[i][((j - 1) << 2) + 3] = 1, num -= 2;
            if (num >= 1) map[i][((j - 1) << 2) + 4] = 1, num -= 1;
        }
    }
    m <<= 2;
}

void disMap() {
#ifdef yyfLocal
    rep(i, 1, n) {
        rep(j, 1, m) 
            //if (map[i][j]) 
                pc(map[i][j] + 48);
            //else pc('; ';);
        puts("");
    }
#endif
}

void fill(int x, int y) {
    if (x < 1 || y < 1 || x > n || y > m || map[x][y] == -1 || map[x][y] != 0) 
        return;
    map[x][y] = -1;
    for (int i = 0; i < 4; ++i) 
        fill(x + dir[i][0], y + dir[i][1]);
}

void highlight() {
    rep(i, 1, n) { // 从第一列、最后一列把留白划掉
        if (!map[i][1]) fill(i, 1);
        if (!map[i][m]) fill(i, m);
    }
    rep(i, 1, m) { // 第一行、最后一行划掉留白
        if (!map[1][i]) fill(1, i);
        if (!map[n][i]) fill(n, i);
    }
}

int dfs2(int x, int y) {
    int res = 0;
    if (x < 1 || y < 1 || x > n || y > m || map[x][y] == -1) return 0;
    if (map[x][y] == 1) {
        map[x][y] = -1; // 相当于省略了 vis 数组吧
        for (int i = 0; i < 4; ++i) 
            res += dfs2(x + dir[i][0], y + dir[i][1]);
    } else
        return fill(x, y), 1; // 填圈
    return res;
}

void find() {
    rep(i, 1, n) rep(j, 1, m)
        if (map[i][j] == 1)
            ++ans[convert[dfs2(i, j)]];
}

void output() {
    for (const auto &i : ans)
        printf("%s", std::string(i.second, i.first).data());
    puts("");
}

void solve() {
    clear();
    input();
    disMap();
    highlight();
    find();
    output();
}

signed main() {
#ifdef yyfLocal
	freopen("testdata.in", "r", stdin);
	freopen("testdata.out", "w", stdout);
#else
    #ifdef yyfLemon
        freopen("ancient.in", "r", stdin);
        freopen("ancient.out", "w", stdout);
    #endif
#endif
    int t = 0;
	while (std::cin >> n >> m && (n + m)) 
        printf("Case %lld: ", ++t), solve();
    return ~~(0^_^0);
}