n, ans = int(raw_input()), 0
for i in range(n):
    l, r = map(int, raw_input().split())
    ans += r - l + 1
print ans
