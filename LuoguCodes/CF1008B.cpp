#include <bits/stdc++.h>

int main()
{
    using namespace std;
    int N;
    cin >> N;
    --N;
    int a, b;
    cin >> a >> b;
    int mn = max(a, b);
    while (N--)
    {
        cin >> a >> b;
        if (mn >= max(a, b))
            mn = max(a, b);
        else if (mn >= a && mn <= b)
            mn = a;
        else if (mn >= b && mn <= a)
            mn = b;
        else
            return puts("NO"), 0;
    }
    puts("YES");
}