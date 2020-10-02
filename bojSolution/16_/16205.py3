from sys import stdin
input = stdin.readline

t, s = input().split()
r1, r2, r3 = "", "", ""

if t=="1":
    r1 = s
    r3 = s[0].upper()+s[1:]
    for i in range(len(s)):
        r2 += s[i].lower()
        if i<len(s)-1 and 'A'<=s[i+1]<='Z': r2 += "_"
elif t=="3":
    r3 = s
    r1 = s[0].lower()+s[1:]
    for i in range(len(s)):
        r2 += s[i].lower()
        if i<len(s)-1 and 'A'<=s[i+1]<='Z': r2 += "_"
else:
    r2 = s
    for i in range(len(s)):
        if s[i]=="_": continue
        if i>=1 and s[i-1]=='_': r1 += s[i].upper()
        else: r1 += s[i]
    r3 = r1[0].upper()+r1[1:]

print(r1,r2,r3,sep='\n')