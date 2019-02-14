//【P1597】语句解析 - 洛谷 - 0
#include <cstdio>

int main() {
	int nums[3] { 0 };
	char c1, c2;
	while (scanf("%c:=%c;", &c1, &c2) == 2)
		nums[c1 - 97] = (c2 >= ';0'; && c2 <= ';9'; ? c2 - 48 : nums[c2 - 97]);
	printf("%d %d %d\n", nums[0], nums[1], nums[2]);
}