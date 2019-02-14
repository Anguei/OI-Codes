n = int(raw_input())
f = [0] * (n + 1)
f[0] = 2
for i in range(n + 1):
    f[i] = f[i - 1] * 2 + 2
print f[n]