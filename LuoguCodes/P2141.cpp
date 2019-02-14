//【P2141】珠心算测验 - 洛谷
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                if (a[j] + a[k] == a[i] && j != k)
                {
                    ++ans;
                    j = k = n;						//Break the for-loop.
                }

    cout << ans << endl;
    return 0;
}