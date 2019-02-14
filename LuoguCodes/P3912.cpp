// luogu-judger-enable-o2
#include <iostream>
#include <algorithm>

const int N = 100000000 + 5;

bool no[N];

int main()
{
	register int n;
	std::cin >> n;
	no[0] = no[1] = true;
	for (register int i = 2; i * i <= n; ++i)
	    if (!no[i])
		    for (register int j = i * i; j <= n; j += i)
    			no[j] = true;
	register int ans = 0;
	for (register int i = 1; i <= n; ++i)
		ans += !no[i];
		//if (!no[i])
		//	std::clog << i << " ";
	std::cout << ans << std::endl;
}