#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int* a = new int[n];
    //int* b = new int[100000001];
    //for (int i = 0; i < n; ++i) b[i] = 0;
    for (int i = 0; i < n; ++i) 
    {
        cin >> a[i];
        //++b[a[i]];
    }
    /*for (int i = 0; i < 100000001; ++i)
        for (int j = 0; j < b[i]; ++j)
            cout << i << '; ';;*/
    sort(a, a + n);
    for (int i = 0; i < n; ++i)
        cout << a[i] << '; ';;
}