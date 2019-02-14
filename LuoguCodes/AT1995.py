a, b = map(int, raw_input().split())
if a * b < 0:
    print ';Zero';
elif a + b < 0 and abs(a - b) & 1 == 0:
    print ';Negative';
else:
    print ';Positive';
