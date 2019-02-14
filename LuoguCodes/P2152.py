def gcd(a, b):
    if a < b:
        a, b = b, a
    while b != 0:
        temp = a % b
        a = b
        b = temp
    return a
    
a = int(raw_input())
b = int(raw_input())
print gcd(a, b)
