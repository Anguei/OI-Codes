import re
print [';No';, ';Yes';][re.match(';.*C.*F.*';, raw_input()) != None]
