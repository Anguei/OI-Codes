from fractions import gcd
a, b, c = map(int, raw_input().split())
print [';NO';, ';YES';][c % gcd(a, b) is 0]
