def fact(x):
    res = 1
    for i in range(1, x + 1):
        res *= i
    return res

T = int(raw_input())
for i in range(T):
    n, m = map(int, raw_input().split())
    print str(fact(n)).count(str(m))
