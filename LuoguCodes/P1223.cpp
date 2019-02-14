//【P1223】排队接水 - 洛谷 - 100
#include <cstdio>
#include <iostream> 
#include <algorithm>// for std::sort() ans std::pair 

//using namespace std;

int main()
{
	int n;
	double sum = 0.0f;// 总等待时间。必须是 double 类型，除非最后做除法的时候进行 int 到 double 的强制转换。 
	std::cin >> n;
	// 定义了一个 pair 动态数组， 每个 pair 具有两个 int 类型成员。 
	std::pair<int, int>* a = new std::pair<int, int>[n];// first 成员表示每个人的等待时间 ， second 成员表示序号。 
	for (int i = 0; i < n; ++i)
	{
		std::cin >> a[i].first;
		a[i].second = i + 1;
	}
	std::sort(a, a + n);// 依据 first 成员（接水时间）进行默认的升序排序 。 
	for (int i = 0; i < n; ++i)
	{
		sum += a[i].first * (n - i - 1);// 第 i 人的接水时间乘以 (n - 1) - i ，然后加到 sum 里面。 
										// 因为我是从 0 开始循环的，所以乘的时候要减一。 
		std::cout << a[i].second << '; ';;
	}
	printf("\n%.2f", sum / n);// 按照指定格式输出。 
	delete[] a;// 最后别忘了释放内存，虽然这不必要，但这是个好习惯 。 
	return 0; 
}