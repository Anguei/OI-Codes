n, a, b = map(int, raw_input().split())
ans = 0
for _ in range(n + 1):
    if a <= sum(map(int, list(str(_)))) <= b:
        ans += _
print ans
