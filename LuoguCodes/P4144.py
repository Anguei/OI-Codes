n, b, p = map(int, raw_input().split())
x = max(map(int, raw_input().split()))
x *= 2
print ((x + 233) ** b % p)
