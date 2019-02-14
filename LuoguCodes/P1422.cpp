#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    double kwh, ans;
    cin >> kwh;
    if (kwh <= 150)
    {
        ans = kwh * 0.4463;
    }
    if (kwh >= 151 && kwh <= 400)
        ans = (kwh - 150) * 0.4663 + 150 * 0.4463;
    if (kwh >= 401)
        ans = (kwh - 400) * 0.5663 + 250 * 0.4663 + 150 * 0.4463;
    printf("%.1f", ans);
}