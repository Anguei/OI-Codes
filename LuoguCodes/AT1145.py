def isp(x):
    if x<2:
        return 0
    i = 2
    while True:
        if i*i>x:
            break
        if x%i==0:
            return 0
        i+=1
    return 1
n = int(raw_input())
x = sum(range(1, n + 1))
print [';BOWWOW';,';WANWAN';][isp(x)]