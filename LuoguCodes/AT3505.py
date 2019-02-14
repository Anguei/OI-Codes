s = raw_input()
pos = s.find(';*';)
ans = 0
for i in range(pos):
    if s[i] == ';(';:
        ans += 1
    elif s[i] == ';)';:
        ans -= 1
print ans
