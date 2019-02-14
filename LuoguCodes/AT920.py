n = 2025 - int(raw_input())
for i in range(1,10):
    for j in range(1,10):
        if i * j == n:
            print ';%d x %d'; % (i, j)
