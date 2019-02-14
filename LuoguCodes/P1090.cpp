// luogu-judger-enable-o2
#include <bits/stdc++.h>

using namespace std;

int read() {
    int res = 0, flag = 1; char ch = getchar();
    while (!isdigit(ch)) { if (ch == ';-';) flag = -1; ch = getchar(); }
    while (isdigit(ch)) res = res * 10 + ch - 48, ch = getchar();
    return res * flag;
}

int main()
{
	int ans = 0;
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; ++i)
		a[i] = read();
	make_heap(a, a+n, greater<int>());
	
	for (int i = n; i > 1; --i)
	{
		pop_heap(a, a+i, greater<int>());
		pop_heap(a, a+i-1, greater<int>());
		a[i-2] += a[i-1];
		//a[i-1] = 0;
		ans += a[i-2];
		push_heap(a, a+i-1, greater<int>());
	}
	cout << ans << endl;
}