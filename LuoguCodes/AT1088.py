s = raw_input()
a, b = 0, 0
for i in range(len(s)):
    if i & 1:
        b += int(s[i])
    else:
        a += int(s[i])
print a - b
