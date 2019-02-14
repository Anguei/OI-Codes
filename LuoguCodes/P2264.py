import re
n, good, dictionary, ans, sentences = int(raw_input()), set(), set(), 0, []
for i in range(n):
    good.add(raw_input().lower())
    
article = raw_input().lower().split(';.';)
#sentences = re.sub(r';[^a-z]';, '; ';, sentences).split()
for sentence in article:
    tmp = re.sub(r';[^a-z]';, '; ';, sentence)
    sentences.append(tmp)

#print sentences

for sentence in sentences:
    appeared = set()
    for word in sentence.split():
        appeared.add(word)
    #print appeared
    for word in appeared:
        if word in good:
            ans += 1
print ans


';';';for word in sentences:
    dictionary.add(word)
    
for word in dictionary:
    if word in good:
        ans += 1
print ans
';';';
