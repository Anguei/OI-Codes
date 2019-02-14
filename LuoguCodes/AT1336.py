n, t = map(int, raw_input().split())
last = int(raw_input())
sum = 0
for _ in range(n - 1):
    new = int(raw_input())
    sum += [new - last, t][new - last > t]
    last = new
print sum + t
