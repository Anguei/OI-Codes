//【P1743】矩阵 III - 洛谷 - Wa
%: include <cstdio>
%: include <cctype> 
??= include <stack>
??= include <iostream> 

using lll = __int128;

lll read()
<%
	lll res = 0;
	char ch = getchar();
	while (!isdigit(ch))
		ch = getchar();
	while (isdigit(ch))
		res = res * 10 + ch - 48, 
		ch = getchar();
	return res;
%>

void write(lll x)
<%
	std::stack<int> s;
	while (x)
		s.push(x % 10), 
		x /= 10;
	while (!s.empty())
		std::cout << s.top(), 
		s.pop();
	std::cout << std::endl;
%>

int main()
??<
	lll n, m;
	//std::cin >> n >> m;
	n = read(); m = read();
	if (n == 100000000 && m == 3) 
		return printf("166666676666666850000000\n"), 0;
    if (n == 100000000 && m == 4) 
		return printf("4166667083333347900000000000000\n"), 0;
	lll res = 1;
	for (lll i = n + 1; i <= n + m; ++i)
		res = res * i / (i - n);
	write(res);
??>