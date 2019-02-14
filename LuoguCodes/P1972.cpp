//【P1972】[SDOI2009]HH的项链 - 洛谷 - Ac & Wa
#include <cctype>
#include <cstdio>
#include <iostream>
#include <algorithm>

int n, m;

int a[500005];
int first[1000005]; // 贝壳第一次出现的位置
int next[500005]; // 贝壳下一次出现的位置 
int bit[500005];

int read()
{
	int res = 0;
	char ch = getchar();
	while (!isdigit(ch))
		ch = getchar();
	while (isdigit(ch))
	{
		res = res * 10 + ch - 48;
		ch = getchar();
	}
	return res;
}

struct Question
{
	int l, r, id, ans;
} q[200005];

int lowbit(int x)
{
	return x & -x;
}

void add(int pos, int val)
{
	while (pos <= n)
	{
		bit[pos] += val;
		pos += lowbit(pos);
	}
}

int query(int pos)
{
	int res = 0;
	while (pos)
	{
		res += bit[pos];
		pos -= lowbit(pos);
	}
	return res; 
}

int main()
{
	int max = 0;
	n = read();
	for (int i = 1; i <= n; ++i)
		max = std::max(max, a[i] = read());
	for (int i = n; i; --i) // 倒序循环方便 
	{
		next[i] = first[a[i]]; // 当前贝壳下一次出现位置即未更新的第一次出现位置（因为倒序） 
		first[a[i]] = i; // 第一次出现的序号越来越小 
	}
	for (int i = 1; i <= max; ++i)
		if (first[i]) // 出现过
			add(first[i], 1); // 扔进去 
	m = read();
	for (int i = 1; i <= m; ++i) 
		q[i].l = read(), q[i].r = read(), q[i].id = i;
	std::sort(q + 1, q + m + 1, [](const Question &q1, const Question &q2) { return q1.l == q2.l ? q1.r < q2.r : q1.l < q2.l; });
	
	int l = 0;
	for (int i = 1; i <= m; ++i)
	{
		while (l < q[i].l)
		{
			if (next[l])
				add(next[l], 1);
			++l;
		}
		q[i].ans = query(q[i].r) - query(q[i].l - 1);
	}
	std::sort(q + 1, q + m + 1, [](const Question &q1, const Question &q2) { return q1.id < q2.id; });
	for (int i = 1; i <= m; ++i)
		printf("%d\n", q[i].ans);
}

/*#include <cctype>
#include <vector>
#include <iostream>
#include <algorithm>

const int kMaxN = 500000, kMaxM = 200000;

int n, m;

int a[kMaxN + 5], next[kMaxN + 5], p[kMaxN + 5], bit[kMaxN + 5];

struct Question
{
    int l, r, id, ans;
} q[kMaxM + 5];

void read(int &x)
{
    x = 0;
    char ch = getchar();
    while (!isdigit(ch)) 
        ch = getchar();
    while (isdigit(ch)) 
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
}

void write(int x)
{
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + 48);
}

int lowbit(int x)
{
    return x & -x;
}

void add(int pos, int val)
{
    while (pos <= n)
    {
        bit[pos] += val;
        pos += lowbit(pos);
    }
}

int query(int pos)
{
    int res = 0;
    while (pos)
    {
        res += bit[pos];
        pos -= lowbit(pos);
    }
    return res;
}

int main()
{
    std::cin >> n;
    //read(n);
    int max = 0;
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> a[i];
        //read(a[i]);
        max = std::max(max, a[i]);
    }
    for (int i = n; i >= 1; --i)
    {
        next[i] = p[a[i]];
        p[a[i]] = i;
    }
    for (int i = 1; i <= max; ++i)
        if (p[i])
            add(p[i], 1);
    read(m);
    for (int i = 1; i <= m; ++i)
    {
        std::cin >> q[i].l >> q[i].r;
        //read(q[i].l), read(q[i].r);
        q[i].id = i;
    }
    std::sort(q + 1, q + m + 1, [](const Question &q1, const Question &q2)
    {
        if (q1.l != q2.l)
            return q1.l < q2.l;
        return q1.r < q2.r;
    });
    int l = 1;
    for (int i = 1; i <= m; ++i)
    {
        while (l < q[i].l)
        {
            if (next[l])
                add(next[l], 1);
            ++l;
        }
        q[i].ans = query(q[i].r) - query(q[i].l - 1);
    }
    std::sort(q + 1, q + m + 1, [](const Question &q1, const Question &q2)
    {
        return q1.id < q2.id;
    });
    for (int i = 1; i <= m; ++i)
    {
        std::cout << q[i].ans << std::endl;
        //write(q[i].ans);
        //putchar(';\n';);
    }
}*/

/*int main()
{
    int n;
    read(n);
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    int m;
    read(m);
    while (m--)
    {
        int l, r, ans = 0;
        std::cin >> l >> r;
        std::vector<bool> vis(n + 1);
        for (int i = l; i <= r; ++i)
            if (!vis[a[i]])
            {
                vis[a[i]] = true;
                ++ans;
            }
        std::cout << ans << std::endl;
    }
}*/

/*int main()
{
    int n;
    read(n);
    std::vector<int> v(n + 1);
    int i, limit = n - 3;
    for (i = 1; i <= limit; i += 4)
    {
        read(v[i]);
        read(v[i + 1]);
        read(v[i + 2]);
        read(v[i + 3]);
    }
    for (; i <= n; ++i)
        read(v[i]);
    int m;
    read(m);
    limit = m - 3;
    for (i = 1; i <= limit; i += 4)
    {
        std::vector<bool> vis(n + 1);
        int l, r, ans = 0, j;
        read(l), read(r);
        for (j = l; j <= r - 3; j += 4)
        {
            if (!vis[v[j]])
            {
                vis[v[j]] = true;
                ++ans;
            }
            if (!vis[v[j + 1]])
            {
                vis[v[j + 1]] = true;
                ++ans;
            }
            if (!vis[v[j + 2]])
            {
                vis[v[j + 2]] = true;
                ++ans;
            }
            if (!vis[v[j + 3]])
            {
                vis[v[j + 3]] = true;
                ++ans;
            }
            
        }
        for (; j <= r; ++j)
            if (!vis[v[j]])
            {
                vis[v[j]] = true;
                ++ans;
            }
        write(ans); putchar(';\n';);
    }
    for (; i <= m; ++i)
    {
        std::vector<bool> vis(n + 1);
        int l, r, ans = 0, j;
        read(l), read(r);
        for (j = l; j <= r - 3; j += 4)
        {
            if (!vis[v[j]])
            {
                vis[v[j]] = true;
                ++ans;
            }
            if (!vis[v[j + 1]])
            {
                vis[v[j + 1]] = true;
                ++ans;
            }
            if (!vis[v[j + 2]])
            {
                vis[v[j + 2]] = true;
                ++ans;
            }
            if (!vis[v[j + 3]])
            {
                vis[v[j + 3]] = true;
                ++ans;
            }
            
        }
        for (; j <= r; ++j)
            if (!vis[v[j]])
            {
                vis[v[j]] = true;
                ++ans;
            }
        write(ans); putchar(';\n';);
    }
}*/