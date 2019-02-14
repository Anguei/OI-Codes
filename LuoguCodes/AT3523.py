s = raw_input()
ans = ';';
for i in range(len(s)):
    if i & 1 == 0:
        ans += s[i]
print ans
