import re
p = ';A?KIHA?BA?RA?$';
s = raw_input()
print [';NO';, ';YES';][re.match(p, s) != None]
