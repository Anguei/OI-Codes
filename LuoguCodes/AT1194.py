n = int(raw_input())
ans = []
for i in range(min(n, 1000), 0, -1):
    if sum(list(map(int, list(str(n - i))))) == i:
        ans.append(n - i)
print len(ans)
for i in ans:
    print i
