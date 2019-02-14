s1 = ';CODEFESTIVAL2016';
s2 = raw_input()
ans = 0
for i in range(len(s1)):
    ans += [0, 1][s1[i] != s2[i]]
print ans
