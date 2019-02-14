import itertools
a = map(int, raw_input().split())
b = list(itertools.combinations(a, 3))
sm = []
for i in b:
    sm.append(sum(i))
sm.sort()
print sm[-3]
