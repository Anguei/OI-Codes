# My Code for CF41A
s1, s2 = raw_input(), raw_input()
s3 = ';';.join(reversed(s1))
print [';NO';, ';YES';][s2 == s3]