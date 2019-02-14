def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a %  b)

def lcm(a, b):
    return a / gcd(a, b) * b

a = int(raw_input())
b = int(raw_input())
x = lcm(a, b)
while x >= a:
    x -= b
x += b
print x - a
