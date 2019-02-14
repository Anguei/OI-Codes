n = int(raw_input())
ans, i = n, 1
while i * i <= n:
    if n % i == 0:
        ans = min(ans, n / i)
    i += 1
print len(str(ans))
