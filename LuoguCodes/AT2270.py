n = int(raw_input())
t = map(int, raw_input().split())
s = sum(t)
m = int(raw_input())
for _ in range(m):
    p, x = map(int, raw_input().split())
    print s - t[p - 1] + x
