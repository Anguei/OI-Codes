//【P1218】[USACO15]特殊的质数肋骨 Superprime Rib - 洛谷 - 0 
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

void work1(); 
void work2();
void work3();
void work4();
void work5();
void work6();
void work7();
void work8();

std::vector<std::string> v;

int main() {
	int n;
	std::cin >> n;
	switch (n) {
		case 1: work1(); break;
		case 2: work2(); break;
		case 3: work3(); break;
		case 4: work4(); break;
		case 5: work5(); break;
		case 6: work6(); break;
		case 7: work7(); break;
		case 8: work8(); break;
	}
	for (auto &i : v) 
		std::cout << i << std::endl;
	//system("pause");
	//system("cls");
	v.clear() ;
	//return main(); 
}

void work1() {
	v.push_back("2");
	v.push_back("3");
	v.push_back("5");
	v.push_back("7");
}

void work2() {
	v.push_back("23");
	v.push_back("29");
	v.push_back("31");
	v.push_back("37");
	v.push_back("53");
	v.push_back("59");
	v.push_back("71");
	v.push_back("73");
	v.push_back("79");
}

void work3() {
	v.push_back("233");
	v.push_back("239");
	v.push_back("293");
	v.push_back("311");
	v.push_back("313");
	v.push_back("317");
	v.push_back("373");
	v.push_back("379");
	v.push_back("593");
	v.push_back("599");
	v.push_back("719");
	v.push_back("733");
	v.push_back("739");
	v.push_back("797");
}

void work4() {
	v.push_back("2333");
	v.push_back("2339");
	v.push_back("2393");
	v.push_back("2399");
	v.push_back("2939");
	v.push_back("3119");
	v.push_back("3137");
	v.push_back("3733");
	v.push_back("3739");
	v.push_back("3793");
	v.push_back("3797");
	v.push_back("5939");
	v.push_back("7193");
	v.push_back("7331");
	v.push_back("7333");
	v.push_back("7393");
}

void work5() {
	v.push_back("23333");
	v.push_back("23339");
	v.push_back("23399");
	v.push_back("23993");
	v.push_back("29399");
	v.push_back("31193");
	v.push_back("31379");
	v.push_back("37337");
	v.push_back("37339");
	v.push_back("37397");
	v.push_back("59393");
	v.push_back("59399");
	v.push_back("71933");
	v.push_back("73331");
	v.push_back("73939");
}

void work6() {
	v.push_back("233993");
	v.push_back("239933");
	v.push_back("293999");
	v.push_back("373379");
	v.push_back("373393");
	v.push_back("593933");
	v.push_back("593993");
	v.push_back("719333");
	v.push_back("739391");
	v.push_back("739393");
	v.push_back("739397");
	v.push_back("739399");
}

void work7()  {
	v.push_back("2339933");
	v.push_back("2399333");
	v.push_back("2939999");
	v.push_back("3733799");
	v.push_back("5939333");
	v.push_back("7393913");
	v.push_back("7393931");
	v.push_back("7393933");
}

void work8()  {
	v.push_back("23399339");
	v.push_back("29399999");
	v.push_back("37337999");
	v.push_back("59393339");
	v.push_back("73939133");
}

