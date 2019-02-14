//【P1047】校门外的树 - 洛谷 - 70
#include <iostream> 
#include <algorithm>

using namespace std;

int main()
{
	int l, m, ans = 0;
	cin >> l >> m;
	bool* trees = new bool[l + 1];
	for (int i = 0; i < l + 1; ++i)
		trees[i] = true;
	int* b = new int[m];
	int* e = new int[m];
	for (int i = 0; i < m; ++i)
		cin >> b[i] >> e[i];
	for (int i = 0; i < m; ++i)
		for (int j = b[i]; j <= e[i]; ++j)
			if (trees[j])
				trees[j] = false;
	for (int i = 0; i <= l; ++i)
		if (trees[i])
			++ans;
	cout << ans << endl;
}