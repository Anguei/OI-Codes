import math
a=int(input())
b=int(input())
l, r = 0, 1
while r ** a <= b:
#while math.pow(r, a) <= b:
    l = r
    r *= 2
while l + 1 < r:
    mid = (l + r) // 2
    if mid ** a <= b:
    #if math.pow(mid, a) + 0.0000000001 <= b:
        l = mid
    else:
        r = mid
if l ** a <= b:
#if math.pow(l, a) <= b:
    print(l)
else:
    print(r)
#print(math.floor(math.pow(b,1/a)+0.000000001))
