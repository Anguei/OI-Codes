s, ans = raw_input(), 0
for i in range(len(s) - 1):
    if (len(set(s[i : i + 2])) == 2):
        ans += 1
print ans
