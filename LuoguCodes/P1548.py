n, m = map(int, raw_input().split())
mn = min(n, m)
ans = m * n * (mn + 1) + mn * (mn + 1) * (2 * mn + 1) / 6 - (m + n) * mn * (mn + 1) / 2
bns = n * (n + 1) / 2 * m * (m + 1) / 2 - ans
print ans, bns
