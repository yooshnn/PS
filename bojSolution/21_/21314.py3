def p(s): print(s, end="")

M = m = 0
s = input()
lk = s.rfind("K")
if lk==-1: lk = len(s)

for i, c in enumerate(s):
    if s[i]=="M":
        if lk==len(s) or i>=lk: p(1)
        else: p(int(i<1 or s[i-1]=="K")*5)
    else:
        p(int(i<1 or s[i-1]=="K")*5)
print()
for i, c in enumerate(s):
    if s[i]=="M": p(int(i<1 or s[i-1]=="K"))
    else: p(5)