p = [None] * 26
n, m, q = map(int, raw_input().split())
for i in range(n):
    raw = raw_input()
    for j, k in enumerate(raw):
        if k == ';*';:
            continue
        p[ord(k) - 65] = (i + 1, j + 1)
while q > 0:
    t = raw_input()
    for c in t:
        tmp = ord(c) - 65
        if p[tmp]:
            print (str(p[tmp][0]) + '; '; + str(p[tmp][1]))
        else:
            print ';NA';
    q -= 1
