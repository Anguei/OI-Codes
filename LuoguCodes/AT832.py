a, b = map(int, raw_input().split())
a, b = abs(a), abs(b)
if a == b:
    print ';Draw';
else:
    print [';Ant';, ';Bug';][a > b]
