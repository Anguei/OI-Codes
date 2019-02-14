n, a, ans = int(raw_input()), map(int, raw_input().split()), 0
a.sort(); a.reverse()
for i in range(0, n, 2): ans += a[i]
print ans
