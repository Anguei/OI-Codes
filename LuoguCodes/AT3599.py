n = int(raw_input())
k = int(raw_input())
ans = 1
for i in range(n):
    ans += min(ans, k)
print ans
