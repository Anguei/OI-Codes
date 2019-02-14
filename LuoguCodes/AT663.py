ans = 0
for i in range(int(raw_input())):
    ans += [0, 1][sum(map(int, raw_input().split())) < 20]
print ans
