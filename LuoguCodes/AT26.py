s = raw_input()
map = { ';i';: ';i';, ';w';: ';w';, ';(';: ';)';, ';)';: ';('; }
ans = 0
for i in range((len(s) + 1) // 2):
    ans += (map[s[i]] != s[len(s) - i - 1])
print ans
