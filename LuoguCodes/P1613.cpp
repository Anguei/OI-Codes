#include <cstring>
#include <iostream>
#include <algorithm>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

const int N = 50 + 5;

using ll = long long;

ll dis[N][N];
bool g[N][N][65];

int main() {
    int n, m;
    std::cin >> n >> m;
    memset(dis, 0x3f, sizeof dis);
    rep(i, 1, m) {
        int u, v;
        std::cin >> u >> v;
        dis[u][v] = 1;
        g[u][v][0] = true;
    }
    rep(l, 1, 64) rep(i, 1, n) rep(j, 1, n) rep(k, 1, n) 
        if (g[i][k][l - 1] && g[k][j][l - 1]) {
            g[i][j][l] = true;
			dis[i][j] = 1;
        }
    rep(k, 1, n) rep(i, 1, n) rep(j, 1, n)
        dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
	std::cout << dis[1][n] << std::endl;
}