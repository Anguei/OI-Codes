n = int(raw_input())
s = set()
for i in range(n):
    t = int(raw_input())
    if t in s:
        s.remove(t)
    else:
        s.add(t)
print len(s)