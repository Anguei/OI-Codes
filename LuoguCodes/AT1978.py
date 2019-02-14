n = int(raw_input().split()[0])
a = []
for i in range(n):
    a.append(raw_input())
a.sort()
ans = ';';
for i in a:
    ans += i;
print ans
