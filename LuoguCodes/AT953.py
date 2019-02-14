from itertools import *
x = list(map(int, raw_input().split()))
ans = 10 ** 18
for (i, j, k) in permutations(x[3:], 3): ans = min(ans, abs(x[0] - i) + abs(x[1] - j) + abs(x[2] - k))
print ans
