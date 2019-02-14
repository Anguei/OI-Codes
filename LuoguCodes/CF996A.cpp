//【CF996A】Hit the Lottery - 洛谷 - Ac 
 #include <iostream> 

int main()
{
	int n;
	std::cin >> n;
	int ans = 0;
	ans += n / 100;
	n %= 100;
	ans += n / 20;
	n %= 20;
	ans += n / 10;
	n %= 10;
	ans += n / 5;
	n %= 5;
	ans += n;
	std::cout << ans << std::endl;
}