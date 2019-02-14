#include <iostream>
using namespace std;
int main()
{
    int h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;
    int ansh = 0, ansm = 0;
    if (m1 > m2)
    {
        ansh += (h2 - h1 - 1);
        ansm += (m2 - m1 + 60);
    }
    else
    {
        ansh += h2 - h1;
        ansm += m2 - m1;
    }
    cout << ansh << " " << ansm;
    return 0;
}