#include <vector>
#include <iostream>
#include <algorithm>

bool check(int mid, int m, const std::vector<int> &d)
{
    int cnt = 0, pos = 0;
    for (int i = 1; i < d.size(); ++i)
        if (d[i] - d[pos] < mid)
        	++cnt;
        else
        	pos = i;
    return cnt <= m;	
}

int main()
{
	//freopen("C:\\Documents and Settings\\Administrator\\My Documents\\下载\\testdata(3).in", "r", stdin);
    int l, n, m;
    std::cin >> l >> n >> m;
    std::vector<int> d(n + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> d[i];
    d.emplace_back(l);
    int lb = 1, rb = d.back();
    int ans = 0;
    while (lb <= rb)
    {
        int mid = (lb + rb) >> 1;
        if (check(mid, m, d))
            lb = mid + 1, ans = lb - 1;
        else
            rb = mid - 1;
    }
    std::cout << ans << std::endl;
}
