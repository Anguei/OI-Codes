a, b = map(int, raw_input().split())
print b / a if (b % a == 0) else b // a + 1
