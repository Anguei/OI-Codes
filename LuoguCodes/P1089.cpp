//【P1089】津津的储蓄计划 - 洛谷 - 40
#include <iostream> 

using namespace std;

int main()
{
    int exp;
    int rest = 0;
    int save = 0;
    for (int i = 1; i <= 12; ++i)
    {
        cin >> exp;
        rest += 300;
        rest -= exp;
        if (rest < 0)
        {
            cout << ';-'; << i << endl;
            return 0;
        }
        int temp = rest; 
        rest -= ((rest / 100) * 100);
        save += ((temp / 100) * 100);
    }
    cout << save * 1.2 + rest << endl;
} 