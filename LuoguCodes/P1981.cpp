#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> nums;
    int n;
    char oper;
    cin >> n;
    nums.push(n);
    while (cin >> oper >> n)
    {
        nums.push(n);
        if (oper == ';*';)
        {
            int a = nums.top();
            nums.pop();
            int b = nums.top();
            nums.pop();
            nums.push((a * b) % 10000);
        }
    }
    int ans = 0;
    while (nums.size())
    {
        ans += nums.top();
        ans %= 10000;
        nums.pop();
    }
    cout << ans % 10000 << endl;
}