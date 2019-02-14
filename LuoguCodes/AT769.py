n = int(raw_input())
a = []
for i in range(n):
    a += [raw_input()]
ans = 0
for j in range(9):
    tmp = ';';
    for i in range(n):
        ch = a[i][j]
        if ch == ';x'; or (ch == ';o'; and tmp != ';o';):
            ans += 1
        tmp = ch
print ans
