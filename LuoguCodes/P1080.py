n = int(raw_input())
a, b = map(int, raw_input().split())
l = []
for i in range(n):
    A, B = map(int, raw_input().split())
    l.append({';A';: A, ';B';: B, ';Val';: A * B})
l.sort(key = lambda x: x[';Val';])
cnt, ans = a, 0
for i in range(n):
    ans = max(ans, cnt // l[i][';B';])
    cnt *= l[i][';A';]
print ans
