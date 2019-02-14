n, pos, ans = 1000 - int(raw_input()), 0, 0
rmb = [500, 100, 50, 10, 5, 1]
for i in rmb:
    ans += n / i
    n -= n / i * i
print ans
