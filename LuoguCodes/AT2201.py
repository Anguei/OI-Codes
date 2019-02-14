dict = { ';b'; : ';d';, ';d'; : ';b';, ';p'; : ';q';, ';q'; : ';p'; }
s = raw_input()
t = ';';.join(map(lambda x : dict[x], list(s[::-1])))
print [';No';, ';Yes';][s == t]
