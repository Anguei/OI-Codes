#include <iostream>

using namespace std;

int main()
{
    struct Data
    {
        int l1;
        int l2;
        int sum;
    }data[7];
    int cur = 8, max = 0;
    for (int i = 0; i < 7; ++i)
    {
        cin >> data[i].l1 >> data[i].l2;
        data[i].sum = data[i].l1 + data[i].l2;
        if (data[i].sum > 8)
            if (i + 1 < cur)
                if (data[i].sum > max)
                {
                    cur = i + 1;
                    max = data[i].sum;
                }
    }
    cout << cur << endl;
}