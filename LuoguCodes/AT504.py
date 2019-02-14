a1, a2, a3=map(int, raw_input().split())
b1, b2, b3=map(int, raw_input().split())
ans = max((a1 / b1) * (a2 / b2) * (a3 / b3), (a1 / b1) * (a3 / b2) * (a2 / b3), (a2 / b1) * (a1 / b2) * (a3 / b3), (a2 / b1) * (a3 / b2) * (a1 / b3), (a3 / b1) * (a1 / b2) * (a2 / b3), (a3 / b1) * (a2 / b2) * (a1 / b3))
print ans
