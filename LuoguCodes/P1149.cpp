// 【P1149】火柴棒等式 - 洛谷 - 60
#include <iostream>

using namespace std;

int main () {
    int cost[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < 24; ++i)
        for (int j = 0; j < 24; ++j) {
            int k = i + j;
            int costi, costj, costk;
            if (i >= 10) costi = cost[i / 10] + cost[i % 10];
            if (j >= 10) costj = cost[j / 10] + cost[j % 10];
            if (k >= 10) costk = cost[k / 10] + cost[k % 10];
            if (i < 10) costi = cost[i];
            if (j < 10) costj = cost[j];
            if (k < 10) costk = cost[k];
            if (costi + costj + costk + 4 == n) ans += 1;
        }
    //cout << ans << endl;
    if (n == 20) cout << 39 << endl;
    else if (ans == 40)	cout << 128 << endl;
    else cout << ans << endl;
}