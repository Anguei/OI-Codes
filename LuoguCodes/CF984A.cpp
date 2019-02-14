#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> nums;
	nums.emplace_back(0);
	while (n--)
	{
		int tmp;
		std::cin >> tmp;
		nums.emplace_back(tmp);
	}
	std::sort(nums.begin(), nums.end());
	std::cout << nums[nums.size() / 2 + (n % 2 == 1)] << std::endl;
}