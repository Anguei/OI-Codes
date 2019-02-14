d = map(int, raw_input().split())
j = map(int, raw_input().split())
ans = 0
for i in range(7):
    ans += max(d[i], j[i])
print ans
