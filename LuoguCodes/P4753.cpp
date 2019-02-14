#include <bits/stdc++.h>

void cannot()
{
    puts("NO");
    exit(0);
}

int main()
{
    int n, m, s;
    std::cin >> n >> m >> s;
    std::vector<int> w(m + 2);
    std::vector<bool> vis(m + 2);
    for (int i = 1; i <= m; ++i)
        std::cin >> w[i];
    w[m + 1] = n;
    std::vector<int> ans;
    int last = 0;
    for (int i = 1; i <= m + 1; ++i)
    {
        if (w[i] - w[last] >= s)
        {
            ans.emplace_back(i);
            last = i;
            vis[i] = true;
        }
    }
    if (last != m + 1)
    	cannot();
    for (int i = m; i >= 0; --i)
    {
        if (!vis[i] && w[last] - w[i] >= s)
        {
            ans.emplace_back(i);
            last = i;
            vis[i] = true;
        }
    }
    if (ans.size() < m + 2) 
    	cannot();
    puts("YES");
    for (auto i : ans)
        std::cout << i << " ";
    puts("");
}