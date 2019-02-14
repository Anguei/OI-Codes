from collections import *
n = int(raw_input())
ss = []
for _ in range(n):
    ss.append(raw_input())
print Counter(ss).most_common()[0][0]
