s = raw_input()
l, ans, pos = len(s), ';';, 0
while pos < l:
    tmp = 1
    while pos < l - 1 and s[pos] == s[pos + 1]:
        tmp += 1
        pos += 1
    ans += s[pos] + str(tmp)
    pos += 1
print ans
