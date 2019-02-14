arr = [0] * 31
for i in range(28):
    arr[int(raw_input())] += 1
for i in range(1, 31):
    if arr[i] is 0:
        print i
