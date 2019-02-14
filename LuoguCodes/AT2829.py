n = int(raw_input())
a = map(int, raw_input().split())
bit = [0] * (n + 1)

def add(pos, val):
    while pos <= n:
        bit[pos] += val
        pos += pos & -pos
def query(pos):
    res = 0
    while pos:
        res += bit[pos]
        pos -= pos & -pos
    return res
 
ans = 0
for i in a:
    add(i, 1)
    ans += i - query(i)
print ans
