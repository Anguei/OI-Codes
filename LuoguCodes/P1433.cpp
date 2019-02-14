//【P1433】吃奶酪 - 洛谷 - 10
#include <cmath>

#include <iomanip>
#include <iostream>
#include <algorithm>

int n;
double ans = 1e9;
bool vis[16];
struct Point {
    double x,y;
} a[16];

void dfs(int now, double len, int step) {
    if (step == n + 1)
        ans = std::min(ans, len);
    if (len > ans)
        return;
    for (int i = 1; i <= n; ++i)
        if (vis[i] == 0) {
            vis[i] = 1;
            dfs(i, len + sqrt((a[now].x - a[i].x) * (a[now].x - a[i].x) + (a[now].y - a[i].y) * (a[now].y - a[i].y)), step + 1);
            vis[i] = 0;
        }
}
int main() {
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i].x >> a[i].y;
    dfs(0, 0, 1);
    std::cout << std::fixed << std::setprecision(2) << ans << std::endl;
}

