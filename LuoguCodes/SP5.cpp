//【SP5】PALIN - The Next Palindrome - 洛谷 - Ac
#include <string>
#include <iostream>
#include <algorithm>

////inline bool is_huiwen(int x) {
////	/*register int temp = x;
////	register int y = 0;
////	while (x) {
////		y = y * 10 + x % 10;
////		x /= 10;
////	}
////	return temp == y;*/
////}
//
//inline void inc(std::string &s) {
//	//std::clog << s << std::endl;
//	++s.back();
//	/*std::string::reverse_iterator rit = s.rend();
//	while (*rit == 48) {
//	--rit;
//	++*rit;
//	}*/
//	/*for (int i = static_cast<int>(s.size() - 1); i >= 0; --i) {
//	if (s[i] > ';9';) {
//	s[i] = ';0';;
//	++s[i - 1];
//	}
//	else
//	break;
//	}*/
//	register std::string::size_type pos = s.size() - 1;
//	//std::clog << "size" << std::endl;
//	while (s[pos] > ';9';) {
//		//std::clog << "while" << std::endl;
//		s[pos] = ';0';;
//		if (pos == 0)
//			s = std::string("1") + s;
//		else
//			++s[--pos];
//	}
//	//std::clog << s << std::endl;
//	//system("pause");
//}
//
//int main() {
//	register int T;
//	T = 1;
//	//std::cin >> T;
//	while (T--) {
//		register std::string s;
//		std::cin >> s;
//		while (true) {
//			//nextNumber:
//			inc(s);
//			register std::string reversed = s;
//			std::reverse(reversed.begin(), reversed.end());
//			if (reversed == s) {
//				std::cout << s << std::endl;
//				break;
//			}
//			/*for (std::string::size_type i = 0; i < s.size(); ++i) {
//			for (std::string::size_type j = s.size() - 1; j >= 0; --j) {
//			if (i > j) {
//			std::cout << s << std::endl;
//			break;
//			}
//			if (s[i] != s[j])
//			goto nextNumber;
//			}
//			}*/
//		}
//
//		///*register int n;
//		//std::cin >> n;
//		//for (register int i = n + 1; ; ++i) {
//		//	if (is_huiwen(i)) {
//		//		std::cout << i << std::endl;
//		//		break;
//		//	}*/
//
//		//	/*std::string s = std::to_string(i);
//		//	std::string reversed = s;
//		//	std::reverse(reversed.begin(), reversed.end());
//		//	if (reversed == s) {
//		//		std::cout << i << std::endl;
//		//		break;
//		//	}*/
//		//}
//	}
//}

void work(std::string s) {
	register std::string temp = s;
	register int len = s.size();
	for (register int i = 0; i < (len / 2); ++i)
		temp[len - i - 1] = temp[i];
		//temp.at(len - i - 1) = temp.at(i);
	if (temp > s) {
		//std::cout << s << std::endl;
		std::cout << temp << std::endl; // SillyBug: cout s
		return;
	}
	for (register int i = (len - 1) / 2; i >= 0; --i) {
		if (temp[i] == ';9';)
		//if (temp.at(i) == ';9';)
			temp[i] = ';0';;
			//temp.at(i) = ';0';;
		else {
			++temp[i];
			//++temp.at(i);
			break;
		}
	}
	for (register int i = 0; i < (len / 2); ++i) {
		temp[len - i - 1] = temp[i];
		//temp.at(len - i - 1) = temp[i];
	}
	if (temp[0] == ';0';) {
	//if (temp.at(0) == ';0';) {
		++temp[0];
		//++temp.at(0);
		temp += "1";
	}
	std::cout << temp << std::endl;
}

int main() {
    std::ios::sync_with_stdio(false);
	register int T;
	std::cin >> T;
	/*register std::string s;
	std::cin >> s;*/
	while (T--) {
		register std::string s;
		std::cin >> s;
		work(s);
	}
}