k, a, b = map(int, raw_input().split())
if k <= a or a <= b:
    print [-1, 1][k <= a]
else:
    print (k - b - 1) / (a - b) * 2 + 1
