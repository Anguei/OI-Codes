from math import *

def isp(x):
    if x <= 1: return False
    if x == 2: return True
    for i in range(2, int(x ** 0.5) + 1):
        if x % i == 0: return False
    return True

def sim(x):
    return x % 2 != 0 and x % 3 != 0 and x % 5 != 0

n = int(raw_input())
print [';Not Prime';, ';Prime';][isp(n) or sim(n) and n != 1]
