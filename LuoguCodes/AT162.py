n, s = float(raw_input()), raw_input()
dict = { ';A'; : 4, ';B'; : 3, ';C'; : 2, ';D'; : 1, ';F'; : 0 }
ans = 0
for i in s:
    ans += dict[i]
print ans / n

