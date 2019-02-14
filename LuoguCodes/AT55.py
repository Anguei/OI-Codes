n, s = int(raw_input()), raw_input()
ans = len(s)
c = [';A';, ';B';, ';X';, ';Y';]
for i in c:
    for j in c:
        for k in c:
            for l in c:
                bns = len(s.replace(i + j, ';D';).replace(k + l, ';D';))
                cns = len(s.replace(k + l, ';D';).replace(i + j, ';D';))
                ans = min(ans, bns, cns)
print ans
