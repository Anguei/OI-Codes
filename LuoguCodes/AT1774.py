n = int(raw_input())
a = [0] * n
for i in range(n):
    x = int(raw_input()) - 1
    if i == 0:
        a[x] = 100000
    elif i == 1:
        a[x] = 50000
    elif i == 2:
        a[x] = 30000
    elif i == 3:
        a[x] = 20000
    elif i == 4:
        a[x] = 10000
for x in a:
    print x
