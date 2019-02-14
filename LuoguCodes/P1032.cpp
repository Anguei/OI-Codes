//【P1032】字串变换 - 洛谷 - 20
#include <cmath>
#include <ctime>
#include <cfenv>
#include <cctype>
#include <cwchar>
#include <cstdio>
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cstdarg>
#include <clocale>
#include <cstddef>
#include <csetjmp>
#include <cassert>
#include <ctgmath>
#include <ccomplex>
#include <set>
#include <map>
#include <new>
#include <ios>
#include <list>
#include <tuple>
#include <array>
#include <queue> 
#include <deque>
#include <stack>
#include <regex>
#include <limits>
#include <vector>
#include <memory>
#include <thread>
#include <chrono>
#include <random>
#include <string> 
#include <locale>
#include <atomic>
#include <numeric>
#include <complex>
#include <utility>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>
#include <typeinfo>
#include <valarray>
#include <stdexcept>
#include <typeindex>
#include <algorithm>
#include <exception>
#include <functional>
#include <type_traits>
#include <system_error>
#include <forward_list>
#include <initializer_list>
#include <scoped_allocator>

typedef std::pair<std::string, std::string> pss;
typedef std::pair<int, std::string> pis;

std::string A, B;
std::vector<pss> vec;
std::set<std::string> set;
std::queue<pis> q;

inline void bfs() {
	while (q.size()) {
		pis u = q.front();
		q.pop();
		if (u.first > 10) {
			std::cout << "NO ANSWER!" << std::endl;
			exit(0);
		}
		for (unsigned i = 0; i < vec.size(); ++i) {
			if (u.second.find(vec[i].first) != std::string::npos && u.second.find(vec[i].first) != -1) {
				for (unsigned j = u.second.find(vec[i].first); j < u.second.size(); j = u.second.find(vec[i].first, j + 1)) {
					std::string t = u.second;
					t.replace(j, vec[i].first.size(), vec[i].second);
					if (t == B) {
						std::cout << u.first + 1 << std::endl;
						exit(0);
					}
					if (!set.count(t)) {
						q.push(std::make_pair(u.first + 1, t));
						set.insert(t);
					}
				}
			}
		}
	}
}

inline void init() {
	std::cin >> A >> B;
	std::string ta, tb;
	while (std::cin >> ta >> tb) {
		vec.push_back(std::make_pair(ta, tb));
	}
	q.push(std::make_pair(0, A));
}

int main() {
	init();
	bfs();
	std::cout << "NO ANSWER!" << std::endl;
}