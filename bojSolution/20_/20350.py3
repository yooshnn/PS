s = input()
s = s[4:]+s[:4]
for i in range(26):
    s = s.replace(chr(ord("A")+i), str(10+i))
if int(s)%97==1: print("correct")
else: print("incorrect")