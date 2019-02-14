from math import *
n = int(raw_input())
a = []
for i in range(n):
    a.append(int(raw_input()))
a = sorted(a, reverse = True)
ans = 0
for _ in range(n):
    ans += sum([(1 - 2*(_ % 2)) * (a[_] ** 2) * acos(-1)])
print ans
