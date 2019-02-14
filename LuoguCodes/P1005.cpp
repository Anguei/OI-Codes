// luogu-judger-enable-o2
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <numeric>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define fn "task"
//#define int __int128
#define pc(x) putchar(x)
#define fileIn freopen("testdata.in", "r", stdin)
#define fileOut freopen("testdata.out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x" = " << (x) << std::endl
#else
#define dbg(x) x
#endif

class BigInteger {
public:
    static const int MAXN = 45;

    int len, s[MAXN];

    BigInteger() {
        memset(s, 0, sizeof(s));
        len = 1;
    }

    BigInteger(int num) {
        *this = num;
    }

    BigInteger(const char *num) {
        *this = num;
    }

    void clean() {
        while (len > 1 && !s[len - 1]) {
            len--;
        }
    }

    BigInteger operator = (int num) {
        char s[MAXN];
        sprintf(s, "%d", num);
        *this = s;
        return *this;
    }

    BigInteger operator = (const char *num) {
        len = strlen(num);
        for (int i = 0; i < len; i++) {
            s[i] = num[len - i - 1] - ';0';;
        }
        return *this;
    }

    std::string str() const {
        std::string res = "";
        for (int i = 0; i < len; i++) {
            res = (char)(s[i] + ';0';) + res;
        }
        if (res == "") {
            res = "0";
        }
        return res;
    }

    BigInteger operator + (const BigInteger &b) const {
        BigInteger c;
        c.len = 0;
        for (int i = 0, g = 0; g || i < std::max(len, b.len); i++) {
            int x = g;
            if (i < len) {
                x += s[i];
            }
            if (i < b.len) {
                x += b.s[i];
            }
            c.s[c.len++] = x % 10;
            g = x / 10;
        }
        return c;
    }

    BigInteger operator * (const BigInteger &b) {
        BigInteger c;
        c.len = len + b.len;
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < b.len; j++) {
                c.s[i + j] += s[i] * b.s[j];
            }
        }
        for (int i = 0; i < c.len - 1; i++) {
            c.s[i + 1] += c.s[i] / 10;
            c.s[i] %= 10;
        }
        c.clean();
        return c;
    }

    BigInteger operator - (const BigInteger &b) {
        BigInteger c;
        c.len = 0;
        for (int i = 0, g = 0; i < len; i++) {
            int x = s[i] - g;
            if (i < b.len) {
                x -= b.s[i];
            }
            if (x >= 0) {
                g = 0;
            } else {
                g = 1;
                x += 10;
            }
            c.s[c.len++] = x;
        }
        c.clean();
        return c;
    }

    bool operator < (const BigInteger &b) const {
        if (len != b.len) {
            return len < b.len;
        }
        for (int i = len - 1; i >= 0; i--) {
            if (s[i] != b.s[i]) {
                return s[i] < b.s[i];
            }
        }
        return false;
    }

    bool operator > (const BigInteger &b) const {
        return b < *this;
    }

    bool operator <= (const BigInteger &b) {
        return !(b > *this);
    }

    bool operator == (const BigInteger &b) {
        return !(b < *this) && !(*this < b);
    }

    BigInteger operator += (const BigInteger &b) {
        *this = *this + b;
        return *this;
    }

private:
};

std::istream &operator >> (std::istream &in, BigInteger &x) {
    std::string s;
    in >> s;
    x = s.c_str();
    return in;
}

std::ostream &operator << (std::ostream &out, const BigInteger &x) {
    out << x.str();
    return out;
}


int read() {
    int res = 0, flag = 1; char ch = getchar();
    while (!isdigit(ch)) { if (ch == ';-';) flag = -1; ch = getchar(); }
    while (isdigit(ch)) res = res * 10 + ch - 48, ch = getchar();
    return res * flag;
}

void print(int x) {
    if (x < 0) putchar(';-';), x = -x;
    if (x > 9) print(x / 10);
    putchar(x % 10 + 48);
}

const int N = 80 + 5;
int n, m;
BigInteger ans, a[N], power[N], dp[N][N];

BigInteger dfs(int i, int j) {
	int k = m - j + i;
	if (!(dp[i][j] == -1)) return dp[i][j];
	if (j - i >= 1) return dp[i][j] = std::max(a[i] * power[k] + dfs(i + 1, j), dfs(i, j - 1) + a[j] * power[k]);
	else return dp[i][j] = a[i] * power[k];
}

void solution() {
    std::cin >> n >> m;
    power[0] = 1; rep(i, 1, N - 1) power[i] = power[i - 1] * 2;
    rep(i, 1, n) {
    	rep(ii, 1, N - 1) rep(jj, 1, N - 1) dp[ii][jj] = BigInteger(-1);
    	rep(j, 1, m) std::cin >> a[j];
    	ans += dfs(1, m);
	}
    std::cout << ans << std::endl;
}

signed main() {
#ifdef yyfLocal
    //fileIn;
    //fileOut;
#else  
#ifndef ONLINE_JUDGE   
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);
#endif
#endif
    solution();
}