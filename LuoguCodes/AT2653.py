n, m = map(int, raw_input().split())
a = map(int, raw_input().split())
a.sort(reverse = True)
print sum(a[:m])
