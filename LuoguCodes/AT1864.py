n = int(raw_input())
s = [list(raw_input()) for _ in range(n)]
for row in zip(*s):
    print ';';.join(row[::-1])
