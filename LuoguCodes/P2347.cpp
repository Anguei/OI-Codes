//【P2347】砝码称重 - 洛谷 - 0
#include <iostream>
#include <set>

int main() {
	int a1, a2, a3, a4, a5, a6;
	std::cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
	std::set<int> s;
	for (int b1 = 0; b1 <= a1; ++b1)
		for (int b2 = 0; b2 <= a2; ++b2)
			for (int b3 = 0; b3 <= a3; ++b3)
				for (int b4 = 0; b4 <= a4; ++b4)
					for (int b5 = 0; b5 <= a5; ++b5)
						for (int b6 = 0; b6 <= a6; ++b6)
							s.insert(b1 * 1 + b2 * 2 + b3 * 3 + b4 * 5 + b5 * 10 + b6 * 20);
	std::cout << "Total=" << s.size() - 1 << std::endl;
}