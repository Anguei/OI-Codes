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
// #define int long long
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

namespace math
{
    class Unsigned
    {
    public:
        typedef std::uint32_t Digit;
        typedef std::uint64_t Wigit;
        static const unsigned BITS = 32;
 
        Unsigned(Digit u = 0) :
            digits(1, u)
        {
            // empty
        }
 
        Unsigned(const std::string& s) :
            digits(1, 0)
        {
            std::istringstream iss(s);
            iss >> *this;
            if (iss.fail() || !iss.eof())
            {
                throw std::runtime_error("Error: Unsigned::string");
            }
        }
 
        Unsigned(const Unsigned& copy) :
            digits(copy.digits)
        {
            // empty
        }
 
        Unsigned& operator= (const Unsigned& rhs)
        {
            digits = rhs.digits;
            return *this;
        }
 
        Unsigned operator++ (int)
        {
            Unsigned w(*this);
            ++(*this);
            return w;
        }
 
        Unsigned& operator++ ()
        {
            for (size_t j = 0; j < digits.size() && ++digits[j] == 0; ++j);
            if (digits.back() == 0)
            {
                digits.push_back(1);
            }
            return *this;
        }
 
        Unsigned operator-- (int)
        {
            Unsigned w(*this);
            --(*this);
            return w;
        }
 
        Unsigned& operator-- ()
        {
            if (digits.back() == 0)
            {
                throw std::underflow_error("Error: Unsigned::underflow");
            }
            for (size_t j = 0; j < digits.size() && digits[j]-- == 0; ++j);
            trim();
            return *this;
        }
 
        friend Unsigned operator+ (const Unsigned& u, const Unsigned& v)
        {
            Unsigned w(u);
            w += v;
            return w;
        }
 
        Unsigned& operator+= (const Unsigned& rhs)
        {
            const size_t n = rhs.digits.size();
            if (digits.size() < n)
            {
                digits.resize(n, 0);
            }
            size_t j = 0;
            Wigit k = 0;
            for (; j < n; ++j)
            {
                k = k + digits[j] + rhs.digits[j];
                digits[j] = static_cast<Digit>(k);
                k >>= BITS;
            }
            for (; k != 0 && j < digits.size(); ++j)
            {
                k += digits[j];
                digits[j] = static_cast<Digit>(k);
                k >>= BITS;
            }
            if (k != 0)
            {
                digits.push_back(1);
            }
            return *this;
        }
 
        friend Unsigned operator- (const Unsigned& u, const Unsigned& v)
        {
            Unsigned w(u);
            w -= v;
            return w;
        }
 
        Unsigned& operator-= (const Unsigned& rhs)
        {
            if ((*this) < rhs)
            {
                throw std::underflow_error("Error: Unsigned::underflow");
            }
            size_t j = 0;
            Wigit k = 0;
            for (; j < rhs.digits.size(); ++j)
            {
                k = k + digits[j] - rhs.digits[j];
                digits[j] = static_cast<Digit>(k);
                k = ((k >> BITS) ? -1 : 0);
            }
            for (; k != 0 && j < digits.size(); ++j)
            {
                k += digits[j];
                digits[j] = static_cast<Digit>(k);
                k = ((k >> BITS) ? -1 : 0);
            }
            trim();
            return *this;
        }
 
        friend Unsigned operator* (const Unsigned& u, const Unsigned& v)
        {
            const size_t m = u.digits.size();
            const size_t n = v.digits.size();
            Unsigned w;
            w.digits.resize(m + n, 0);
            for (size_t j = 0; j < n; ++j)
            {
                Wigit k = 0;
                for (size_t i = 0; i < m; ++i)
                {
                    k += static_cast<Wigit>(u.digits[i]) * v.digits[j] +
                        w.digits[i + j];
                    w.digits[i + j] = static_cast<Digit>(k);
                    k >>= BITS;
                }
                w.digits[j + m] = static_cast<Digit>(k);
            }
            w.trim();
            return w;
        }
         
        Unsigned& operator*= (const Unsigned& rhs)
        {
            *this = (*this) * rhs;
            return *this;
        }
 
        friend Unsigned operator/ (const Unsigned& u, const Unsigned& v)
        {
            Unsigned q, r;
            u.divide(v, q, r);
            return q;
        }
 
        Unsigned& operator/= (const Unsigned& rhs)
        {
            Unsigned r;
            divide(rhs, *this, r);
            return *this;
        }
 
        friend Unsigned operator% (const Unsigned& u, const Unsigned& v)
        {
            Unsigned q, r;
            u.divide(v, q, r);
            return r;
        }
 
        Unsigned& operator%= (const Unsigned& rhs)
        {
            Unsigned q;
            divide(rhs, q, *this);
            return *this;
        }
 
        void divide(Unsigned v, Unsigned& q, Unsigned& r) const
        {
            // Handle special cases (m < n).
            if (v.digits.back() == 0)
            {
                throw std::overflow_error("Error: Unsigned::overflow");
            }
            r.digits = digits;
            const size_t n = v.digits.size();
            if (digits.size() < n) { q.digits.assign(1, 0); return; } // Normalize divisor (v[n-1] >= BASE/2).
            unsigned d = BITS;
            for (Digit vn = v.digits.back(); vn != 0; vn >>= 1, --d);
            v <<= d;
            r <<= d;
            const Digit vn = v.digits.back();
 
            // Ensure first single-digit quotient (u[m-1] < v[n-1]).
            r.digits.push_back(0);
            const size_t m = r.digits.size();
            q.digits.resize(m - n);
            Unsigned w;
            w.digits.resize(n + 1);
            const Wigit MAX_DIGIT = (static_cast<Wigit>(1) << BITS) - 1;
            for (size_t j = m - n; j-- != 0;)
            {
                // Estimate quotient digit.
                Wigit qhat = std::min(MAX_DIGIT,
                    (static_cast<Wigit>(r.digits[j + n]) << BITS |
                        r.digits[j + n - 1]) / vn);
 
                // Compute partial product (w = qhat * v).
                Wigit k = 0;
                for (size_t i = 0; i < n; ++i)
                {
                    k += qhat * v.digits[i];
                    w.digits[i] = static_cast<Digit>(k);
                    k >>= BITS;
                }
                w.digits[n] = static_cast<Digit>(k);
 
                // Check if qhat is too large (u - w < 0).
                bool is_trial = true;
                while (is_trial)
                {
                    size_t i = n;
                    for (; i != 0 && r.digits[j + i] == w.digits[i]; --i);
                    if ((is_trial = (r.digits[j + i] < w.digits[i])))
                    {
                        // Adjust partial product (w -= v).
                        --qhat;
                        k = 0;
                        for (size_t i = 0; i < n; ++i)
                        {
                            k = k + w.digits[i] - v.digits[i];
                            w.digits[i] = static_cast<Digit>(k);
                            k = ((k >> BITS) ? -1 : 0);
                        }
                        w.digits[n] = static_cast<Digit>(k + w.digits[n]);
                    }
                }
                q.digits[j] = static_cast<Digit>(qhat);
 
                // Compute partial remainder (u -= w).
                k = 0;
                for (size_t i = 0; i < n; ++i)
                {
                    k = k + r.digits[j + i] - w.digits[i];
                    r.digits[j + i] = static_cast<Digit>(k);
                    k = ((k >> BITS) ? -1 : 0);
                }
            }
 
            // Denormalize remainder.
            q.trim();
            r.digits.resize(n);
            r >>= d;
        }
 
        friend Unsigned operator<< (const Unsigned& u, size_t v)
        {
            Unsigned w(u);
            w <<= v;
            return w;
        }
 
        Unsigned& operator<<= (size_t rhs)
        {
            if (digits.back() != 0 && rhs != 0)
            {
                const size_t n = rhs / BITS;
                digits.insert(digits.begin(), n, 0);
                rhs -= n * BITS;
                Wigit k = 0;
                for (size_t j = n; j < digits.size(); ++j)
                {
                    k |= static_cast<Wigit>(digits[j]) << rhs;
                    digits[j] = static_cast<Digit>(k);
                    k >>= BITS;
                }
                if (k != 0)
                {
                    digits.push_back(static_cast<Digit>(k));
                }
            }
            return *this;
        }
 
        friend Unsigned operator>> (const Unsigned& u, size_t v)
        {
            Unsigned w(u);
            w >>= v;
            return w;
        }
 
        Unsigned& operator>>= (size_t rhs)
        {
            const size_t n = rhs / BITS;
            if (n >= digits.size())
            {
                digits.assign(1, 0);
            }
            else
            {
                digits.erase(digits.begin(), digits.begin() + n);
                rhs -= n * BITS;
                Wigit k = 0;
                for (size_t j = digits.size(); j-- != 0;)
                {
                    k = k << BITS | digits[j];
                    digits[j] = static_cast<Digit>(k >> rhs);
                    k = static_cast<Digit>(k);
                }
                trim();
            }
            return *this;
        }
 
        friend Unsigned operator& (const Unsigned& u, const Unsigned& v)
        {
            Unsigned w(u);
            w &= v;
            return w;
        }
 
        Unsigned& operator&= (const Unsigned& rhs)
        {
            const size_t n = rhs.digits.size();
            if (digits.size() > n)
            {
                digits.resize(n);
            }
            for (size_t j = 0; j < digits.size(); ++j)
            {
                digits[j] &= rhs.digits[j];
            }
            trim();
            return *this;
        }
 
        friend Unsigned operator^ (const Unsigned& u, const Unsigned& v)
        {
            Unsigned w(u);
            w ^= v;
            return w;
        }
 
        Unsigned& operator^= (const Unsigned& rhs)
        {
            const size_t n = rhs.digits.size();
            if (digits.size() < n)
            {
                digits.resize(n, 0);
            }
            for (size_t j = 0; j < n; ++j)
            {
                digits[j] ^= rhs.digits[j];
            }
            trim();
            return *this;
        }
 
        friend Unsigned operator| (const Unsigned& u, const Unsigned& v)
        {
            Unsigned w(u);
            w |= v;
            return w;
        }
 
        Unsigned& operator|= (const Unsigned& rhs)
        {
            const size_t n = rhs.digits.size();
            if (digits.size() < n)
            {
                digits.resize(n, 0);
            }
            for (size_t j = 0; j < n; ++j)
            {
                digits[j] |= rhs.digits[j];
            }
            return *this;
        }
 
        friend bool operator< (const Unsigned& u, const Unsigned& v)
        {
            const size_t m = u.digits.size();
            size_t n = v.digits.size();
            if (m != n)
            {
                return (m < n);
            }
            for (--n; n != 0 && u.digits[n] == v.digits[n]; --n);
            return (u.digits[n] < v.digits[n]); } friend bool operator> (const Unsigned& u, const Unsigned& v)
        {
            return (v < u);
        }
 
        friend bool operator<= (const Unsigned& u, const Unsigned& v)
        {
            return !(v < u); } friend bool operator>= (const Unsigned& u, const Unsigned& v)
        {
            return !(u < v);
        }
 
        friend bool operator== (const Unsigned& u, const Unsigned& v)
        {
            return (u.digits == v.digits);
        }
 
        friend bool operator!= (const Unsigned& u, const Unsigned& v)
        {
            return (u.digits != v.digits);
        }
 
        Digit to_uint() const
        {
            return digits[0];
        }
 
        std::string to_string() const
        {
            std::ostringstream oss;
            Unsigned q(*this), r;
            do
            {
                q.divide(10, q, r);
                oss << r.digits[0];
            } while (q.digits.back() != 0);
            std::string s(oss.str());
            std::reverse(s.begin(), s.end());
            return s;
        }
 
        friend std::ostream& operator<< (std::ostream& os, const Unsigned& u)
        {
            os << u.to_string(); return os; } friend std::istream& operator>> (std::istream& is, Unsigned& u)
        {
            char digit = ';\0';;
            is >> digit;
            if (is.good() && std::isdigit(digit))
            {
                u = digit - ';0';;
                while (std::isdigit(is.peek()))
                {
                    is >> digit;
                    u = 10 * u + (digit - ';0';);
                }
            }
            else
            {
                is.setstate(std::ios_base::failbit);
            }
            return is;
        }
 
    private:
        std::vector<Digit> digits;
 
        void trim()
        {
            while (digits.back() == 0 && digits.size() > 1)
            {
                digits.pop_back();
            }
        }
    };
} // namespace math

const int N = 1000 + 5;
int n;
math::Unsigned a[N], dp[N];

math::Unsigned qpow(math::Unsigned a, math::Unsigned b) {
    math::Unsigned res = 1;
    while (b != 0) {
        if (b % 2 != 0) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

void solution() {
    std::cin >> n;
    rep(i, 1, n) std::cin >> a[i];
    rep(i, 1, n) {
        if (a[i] == 0) dp[i] = dp[i - 1];
        else dp[i] = qpow(2, i) - dp[i - 1] - 1;
    }
    std::cout << dp[n] << std::endl;
}

signed main() {
#ifdef yyfLocal
    fileIn;
    // fileOut;
#else  
#ifndef ONLINE_JUDGE   
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);
#endif
#endif
    solution();
}