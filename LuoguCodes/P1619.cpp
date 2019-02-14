#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <algorithm>

using ull = unsigned long long;

int main()
{
#ifdef yyfLocal
	freopen("d:\\Users\\yyf\\Downloads\\testdata (12).in", "r", stdin);
	freopen("d:\\Users\\yyf\\Downloads\\testdata (12).ans", "w", stdout);
#endif
    while (true)
    {
        std::cout << "Enter the number=";;
        std::string s;
        std::getline(std::cin, s);
        std::cout << std::endl;
        
        ull num = 0;
        for (auto i : s)
        	if (isdigit(i))	
        		num = num * 10 + i - 48;
        if (num == 0)
        	break;
        	
        std::cout << "Prime? ";
        bool ok = true;
        for (ull i = 2; i * i <= num; ++i)
        	if (num % i == 0)
        	{
        		ok = false;
        		std::cout << "No!" << std::endl;
        		break;
			}
        if (num == 1)
        {
        	std::cout << "No!" << std::endl << std::endl;
        	continue;
        }
		if (num > 40000000)
		{
			std::cout << "The number is too large!" << std::endl << std::endl;
			continue;
		}
		if (ok)
		{
			std::cout << "Yes!" << std::endl << std::endl;
			continue;
		}
		
		auto isp = [](ull x)
		{
			if (x <= 1)
				return false;
			for (ull i = 2; i * i <= x; ++i)	
				if (x % i == 0)
					return false;
			return true;
		};
		
		std::vector<std::pair<int, int>> ans;
		std::cout << num << "=";
		for (ull i = 2; i <= num; ++i)
		{
			if (num % i == 0 && isp(i))
			{
				int cnt = 0;
				while (num % i == 0)
				{
					++cnt;
					num /= i;
				}
				ans.emplace_back(std::make_pair(i, cnt));
			}
		}
		
		std::cout << ans.front().first << "^" << ans.front().second;
		for (int i = 1; i < ans.size(); ++i)
			std::cout << "*" << ans[i].first << "^" << ans[i].second;
		std::cout << std::endl << std::endl;
		
		continue;
		
#ifdef onlinejudge
        std::string sNum = extract(s);
        if ((sNum.size() > 8) || (sNum.size() == 8&& sNum.front() >= ';4';))
            std::cout << "No!" << std::endl << "The number is too large!" << std::endl;
        else
        {
            int num = std::stoull(sNum);
            bool isp = is_prime(num);
            std::cout << (isp ? "Yes!" : "No!") << std::endl;
            if (!isp && num >= 2)
            {
                std::cout << num << "=";
                factor(num);
                std::cout << std::endl;
            }
        } 
#endif
    }
}