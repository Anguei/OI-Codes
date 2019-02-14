n = int(raw_input())
root = int(pow(n, 1.0 / 3) + 0.5)
print [';NO';, ';YES';][root ** 3 == n]
