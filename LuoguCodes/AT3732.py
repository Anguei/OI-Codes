s = raw_input()
ans = len(s)
for i in range(1, len(s)):
    if s[i - 1] != s[i]:
        ans = min(ans, max(i, len(s) - i))
print ans
