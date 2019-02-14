a = int(raw_input())
fact = 1
tot = 0
for i in range(1, a + 1):
    for j in range(1, i + 1):
        fact *= j
    tot += fact
    fact = 1
print tot
