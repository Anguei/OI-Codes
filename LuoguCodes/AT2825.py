n = int(raw_input())
a = map(int, raw_input().split())
mx, ans = 0, 0
for i in a:
    if mx < i:
        ans += 1
    mx = max(mx, i)
print ans
