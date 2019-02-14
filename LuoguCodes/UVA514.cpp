//【UVA514】Rails - 洛谷 - Wa 
#include <stack>
#include <vector>
#include <iostream>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	while (std::cin >> n && n)
	{
		std::stack<int> s;
		std::vector<int> v(n + 1);
		while (1)
		{
			std::cin >> v[1];
			if (v[1] == 0)
				break;
			for (int i = 2; i <= n; ++i)
				std::cin >> v[i];
			int a = 1; // A 走了多少 
			int b = 1; // B 有了多少 
			bool ok = true;
			while (b <= n) // B 车站未满 
			{
				if (a == v[b]) // 两车相等 
				{
					++a;
					++b;
				}
				else if (!s.empty() && s.top() == v[b]) // C 站栈顶是要去 B 的 
				{
					s.pop();
					++b;
				}
				else if (a <= n) // A 没走光，进 C 
					s.push(a++);
				else
				{
					ok = false; // 走不了了 
					break;
				}
			}
			puts(ok ? "Yes" : "No");
		}
		puts("");
	}
}