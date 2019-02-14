ans = 0
for i in range(int(raw_input())):
  a, b = map(int, raw_input().split())
  ans += (a * b * 1.05)
print int(ans)
