map = [0, 1, 5, 2, 8, 3, 9, 2, 8, 7, 7, 8, 4, 7, 3, 8, 4, 1, 5, 4]
s = ';';
while 1:
    s = input()
    if s == ';0';:
        break
    tmp = int(s[-1])
    if len(s) > 1:
        tmp += int(s[-2]) * 10
    print((map[tmp % 20] + tmp // 20 * 4) % 10)
