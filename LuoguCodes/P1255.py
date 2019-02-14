#【P1255】数楼梯 - 洛谷 - 90
n = int(input())
if n == 0:
	print(0)
else:
	l = [1, 1, 2]
	for i in range(n):
		l[2] = l[0] + l[1]
		l[0] = l[1]
		l[1] = l[2]
	print(l[0])