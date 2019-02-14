from collections import *
n, k = map(int, raw_input().split())
c = Counter(raw_input().split())
s = sorted(c.values())[::-1]
print sum(s[k:])
