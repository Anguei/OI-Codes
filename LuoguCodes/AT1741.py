a = int(raw_input())
b = int(raw_input())
n = int(raw_input())
while (n % a or n % b):
    n += 1
print n
