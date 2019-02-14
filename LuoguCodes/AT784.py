xa, ya, xb, yb, xc, yc = map(int, raw_input().split())
x1 = xb - xa
y1 = yb - ya
x2 = xc - xa
y2 = yc - ya
print float(abs(x1 * y2 - x2 * y1)) / 2