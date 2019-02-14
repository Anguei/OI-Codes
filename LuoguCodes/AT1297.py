n, k = map(int, raw_input().split())
a = []
flag = False
for i in range(n):
    a.append(int(raw_input()))
for i in range(n - 2):
    s = sum(a[i : i + 3])
    if s < k:
        print i + 3
        flag = True
        break
if flag == False:
    print -1
