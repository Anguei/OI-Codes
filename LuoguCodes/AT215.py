a = map(int, raw_input().split())
b = int(raw_input())
c = map(int, raw_input().split())
k = 6 - len(set(a) - set(c))
print [2, {6 : 1, 5 : 3, 4 : 4, 3 : 5}.get(k, 0)][k != 5 or b not in c]
