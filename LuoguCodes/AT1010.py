n, m = map(int, raw_input().split())
nums = map(int, raw_input().split())
ans = 0
for num in nums:
    if m & 1:
       ans += num
    m >>= 1
print ans
