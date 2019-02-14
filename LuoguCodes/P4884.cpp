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
#define ll long long
#define int __int128
#define pc(x) putchar(x)
#define fileIn freopen("testdata.in", "r", stdin)
#define fileOut freopen("testdata.out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#ifdef yyfLocal
#define dbg(x) std::clog << #x" = " << (x) << std::endl
#define logs(x) std::clog << (x) << std::endl
#else
#define dbg(x) 42
#define logs(x) 42
#endif

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

    BigInteger operator % (const BigInteger &b) {

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

int k, mod;
std::map<int, int> map;

int qpow(int a, int b, int mod) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int bsgs(int a, int b, int mod) {
    int res = 0;
    a %= mod;
    if (!a && !b) return 0;
    int m = ceil(sqrt(static_cast<double>(mod)));
    map[1] = m + 1;
    int now = 1;
    rep(i, 1, m - 1) {
        now = now * a % mod;
        map[now] = map[now] ? map[now] : i;
    }
    int inv = 1, powed = qpow(a, mod - m - 1, mod);
    rep(i, 0, m - 1) {
        int ptr = map[b * inv % mod];
        if (ptr) {
            res = m * i + (ptr == m + 1 ? (ptr = 0) : ptr);
            break;
        }
        inv = inv * powed % mod;
    }
    return res;
}

void solution() {
    k = read(), mod = read();
    k *= 9; k += 1; k %= mod;
    print(bsgs(10, k, mod)), puts("");;
}

signed main() {
#ifdef yyfLocal
    fileIn;
    //fileOut;
#else  
#ifndef ONLINE_JUDGE   
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);
#endif
#endif
    solution();
}