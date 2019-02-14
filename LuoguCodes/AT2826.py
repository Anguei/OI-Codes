n = int(raw_input())
s = raw_input().split()
ans = ';';
for i in s:
    ans += i
print int(ans) % 1000000007
