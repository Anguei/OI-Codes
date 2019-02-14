n = raw_input()
ou = 0
ji = 0
for i in range(0, len(n), 2) :
	ji += int(n[i])
for i in range(1, len(n), 2):
	ou += int(n[i])
if len(n) % 2:
	print ou, ji
else:
	print ji, ou
