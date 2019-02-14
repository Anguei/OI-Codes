n, a, b = map(int, raw_input().split())
print max(a - b + (b - a) * max(n - 1, 0) + 1, 0)
