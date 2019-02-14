// luogu-judger-enable-o2
#include <cmath>
#include <ctime>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
#define fn "testdata"
#define ll long long
#define int long long
#define pc(x) putchar(x)
#define endln putchar(';\n';)
#define println(x) print(x), endln
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

const int N = 100000 + 5, jzm = 19260817;

struct Node {
    int key, rank, size;
    Node *lson, *rson;
    Node() {}
    Node(int x, int rank);
} NIL, *root = &NIL;

Node::Node(int x, int rank) : key(x), rank(rank), size(1), lson(&NIL), rson(&NIL) {}

Node *maintain(Node *o) { 
    o->size = 1 + o->lson->size + o->rson->size;
    return o;
}

Node *insert(int x, int rank, Node *o) {
    if (o == &NIL) return root = new Node(x, rank);
    if (x <= o->key) {
        Node *p = insert(x, rank, o->lson);
        if (p->rank > o->rank) o->lson = p->rson, p->rson = maintain(o), o = p;
        else o->lson = p;
    } else {
        Node *p = insert(x, rank, o->rson);
        if (p->rank > o->rank) o->rson = p->lson, p->lson = maintain(o), o = p;
        else o->rson = p;
    }
    return root = maintain(o);
}

Node *zip(Node *l, Node *r) {
    if (l == &NIL) return r;
    if (r == &NIL) return l;
    if (l->rank < r->rank) {
        r->lson = zip(l, r->lson);
        return maintain(r);
    } else {
        l->rson = zip(l->rson, r);
        return maintain(l);
    }
}

Node *del(int x, Node *o) {
    if (o->key == x) return root = zip(o->lson, o->rson);
    if (o->key > x) o->lson = del(x, o->lson);
    else o->rson = del(x, o->rson);
    return root = maintain(o);
}

int getRank(int x) {
    insert(x, jzm, root);
    int res = root->lson->size + 1;
    del(x, root);
    return res;
}

int findKth(int k, Node *o) {
    if (o->lson->size == k - 1) return o->key;
    else if (o->lson->size > k - 1) return findKth(k, o->lson);
    else return findKth(k - o->lson->size - 1, o->rson);
}

int prev(int x) {
    insert(x, jzm, root);
    Node *o = root->lson;
    while (o->rson != &NIL) o = o->rson;
    del(x, root);
    return o->key;
}

int suff(int x) {
    insert(x + 1, jzm, root);
    Node *o = root->rson;
    while (o->lson != &NIL) o = o->lson;
    del(x + 1, root);
    return o->key;
}

void solution() {
    srand(time(nullptr)); int Q = read(); while (Q--) {
        int opt = read(), x = read();
        switch (opt) {
            case 1: insert(x, rand() % jzm, root); break;
            case 2: del(x, root); break;
            case 3: println(getRank(x)); break;
            case 4: println(findKth(x, root)); break;
            case 5: println(prev(x)); break;
            case 6: println(suff(x)); break;
        }
    }
}

signed main() {
#ifdef yyfLocal
    fileIn;
    // fileOut;
#else  
#ifndef ONLINE_JUDGE   
    freopen(fn ".in", "r", stdin);
    freopen(fn ".out", "w", stdout);
#endif
#endif
    logs("main.exe");
    solution();
}